*** UID:0000E6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000O9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000O9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
typedef mystr::StringBase<char, mystr::mychar_traits<char> > StringBaseA;
typedef mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > StringBaseW;

class StdioFile : public File
{
public:
    StdioFile();
    virtual ~StdioFile();

    virtual void Open(const wchar_t *path);
    virtual bool Close();
    virtual int GetPosition();
    virtual bool Seek(int offset, int origin);
    virtual int GetSize();
    virtual size_t Read(void *buffer, int count);
    virtual bool ReadLine(StringBaseA &line);
    virtual int ReadLineChars(char *buffer, int limit);

    bool ReadLine(StringBaseW &line);
    int ReadRemaining(_AUTOBUF<unsigned char> &buffer);

private:
    FILE *m_fileHandle;
    int m_fileSize;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# StdioFile

## Status

- Confidence: very strong for class behavior, exact 12-byte layout, complete virtual declarations, and File override compatibility; exact historical field/type spelling and compilation-unit split remain caps.
- Proposed path: [UID:0000O9][StdioFile](by-file/StdioFile.md), under the [UID:0000JD][FileIO](by-file/FileIO.md) utility layer
- Parent attachment: [UID:0000O9][StdioFile](by-file/StdioFile.md); both the class and file root now clear the strict 85/85 gate.
- Current Wave3 file: `class_StdioFile.cpp`
- Main address evidence: [UID:0001IR][0x00582070-0x005824f6.StdioFile](by-memory/0x00582070-0x005824f6.StdioFile.md), [UID:0001IT][0x005820d0-0x005821c9.StdioFileOpen](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md), [UID:0001IV][0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods](by-memory/0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods.md), plus [UID:00019F][0x004f5ad0-0x004f5ad4.StdioFileGetSize](by-memory/0x004f5ad0-0x004f5ad4.StdioFileGetSize.md)
- Size/layout: 12 bytes; `File` base at `+0`, inferred `FILE* m_fileHandle` at `+4`, inferred `m_fileSize` / cached file size at `+8`. See [UID:0003H2][StdioFileLayout](by-type/by-struct/StdioFileLayout.md) and the mixed index [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md). Exact original field spellings remain inferred, not symbol-proven.
- Vtable/type evidence: [UID:0003I1][StdioFileVtable](by-type/by-vtable/StdioFileVtable.md), split from shared index [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md)
- 2026-07-01 source declaration, corrected by the UID0002UV Gate 2 repair: the class shell emits at position `0`, closes with `};`, and then places `[[CHILDREN]]` before method bodies. The declaration uses VC6/VC7-safe typedef spacing for `StringBaseA` / `StringBaseW`, keeps `Open` as `void` because direct callers ignore the retained `FILE*` register value, preserves `GetPosition` as the current source-facing name with `Tell` as historical vocabulary, and documents `_AUTOBUF<unsigned char>` ownership for `ReadRemaining`.

## UID0002UV Source-Quality Callback

- Preserved the complete accepted StdioFile declaration order, fields, helper methods, and signed-count correction; the Gate 2 repair moves only `[[CHILDREN]]` after `};` so qualified definitions are emitted outside the class.
- File is a four-byte data-member-free base. `m_fileHandle` at `+0x04` and `m_fileSize` at `+0x08` are StdioFile members, producing the compiler-confirmed complete size `0x0c`.
- DATFile's common-slot implementation explicitly tests `count < 0` and substitutes the full payload size. That branch proves the shared virtual parameter is signed even though this implementation passes it to `fread`.
- The `Read` return remains `size_t`, preserving exact CRT byte-count behavior.
- `Open`, `Close`, `GetPosition`, `Seek`, `GetSize`, ANSI/wide line methods, raw line method, and `ReadRemaining` are unchanged.
- Existing constructor/destructor, error handling, no-null-guard, line-read, buffer replacement, caller, vtable, source placement, and historical evidence remain intact.
- Raised only this page from `90/89` to `91/92`; owner/emitter, position `0`, and source route remain unchanged.

## Role

`StdioFile` is the loose-filesystem implementation of the [UID:00004V][File](by-class/File.md) stream interface. It opens a wide path in binary-read mode, tracks the total file size from `_wstat`, and exposes virtual read/seek/line-reading methods to callers that can also work with [UID:00003G][DATFile](by-class/DATFile.md).

## Confirmed Methods

| Address | Method | Notes |
| --- | --- | --- |
| [UID:0001IQ][0x00582070-0x0058209a.StdioFileConstructor](by-memory/0x00582070-0x0058209a.StdioFileConstructor.md) | `StdioFile::StdioFile` | Source-ready at `90/93`; formal first-draft C++ initializes inferred `m_fileHandle = NULL` and `m_fileSize = 0`. Current MCP session `3fa0535f` reconfirmed exact `0x2a` body bytes, `0xcc` padding, one-block/no-string/no-constant constructor, one inherited base-constructor callee, five construction callers, and vtable install. |
| [UID:0001IS][0x005820a0-0x005820c7.StdioFileDestructor](by-memory/0x005820a0-0x005820c7.StdioFileDestructor.md) | destructor | Closes the handle if present, restores `File` vtable, destroys `LObject`. |
| [UID:0001IT][0x005820d0-0x005821c9.StdioFileOpen](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md) | `Open` | Calls `_wstat64i32`-compatible wide stat, opens with `L"rb"`, stores handle and stat size, throws [UID:00004X][FileError](by-class/FileError.md) on failure, and is declared `void` because all direct callers ignore the retained `FILE*` in `EAX`. |
| [UID:0001IU][0x005821d0-0x005821f7.StdioFileClose](by-memory/0x005821d0-0x005821f7.StdioFileClose.md) | `Close` | Closes the handle and clears cached size; returns close success. It does not clear `m_fileHandle`. |
| [UID:0001IV][0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods](by-memory/0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods.md) | `GetPosition` | Returns `ftell(handle)`. |
| [UID:0001IV][0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods](by-memory/0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods.md) | `Seek` | Returns whether `fseek(handle, offset, origin)` succeeded. |
| [UID:00019F][0x004f5ad0-0x004f5ad4.StdioFileGetSize](by-memory/0x004f5ad0-0x004f5ad4.StdioFileGetSize.md) | `GetSize` | Returns cached size at offset `+8`. |
| [UID:0001IV][0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods](by-memory/0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods.md) | `Read` | Reads bytes through `fread(buffer, 1, count, handle)`. |
| [UID:0001IW][0x00582250-0x005822c1.StdioFileReadLineChars](by-memory/0x00582250-0x005822c1.StdioFileReadLineChars.md) | `ReadLineChars` | Reads into caller buffer until CR/LF/low-byte `0xff`/limit, preserving first-read EOF, CR extra-consume, exact-limit `-1`, zero-limit `-1`, and negative-limit `0` behavior. |
| [UID:0001IX][0x005822d0-0x00582379.StdioFileReadLine](by-memory/0x005822d0-0x00582379.StdioFileReadLine.md) | `ReadLine` | Builds a `StringBaseA` line with CR/LF handling; first-read EOF returns false without assigning the destination. |
| [UID:0002RH][0x00582380-0x00582405.StdioFileReadLineWideHelper](by-memory/0x00582380-0x00582405.StdioFileReadLineWideHelper.md) | `ReadLine` wide overload | Non-virtual helper that calls the virtual ANSI slot, converts/assigns `StringBaseW` unconditionally, and returns the ANSI read status. |
| [UID:0001IY][0x00582410-0x00582459.StdioFileReadRemaining](by-memory/0x00582410-0x00582459.StdioFileReadRemaining.md) | `ReadRemaining` | Allocates a buffer for bytes from current position to EOF and reads them, preserving the duplicate destination-buffer delete/free before replacement allocation. |
| [UID:0001J0][0x005824a0-0x005824f6.StdioFileScalarDeletingDestructor](by-memory/0x005824a0-0x005824f6.StdioFileScalarDeletingDestructor.md) | scalar deleting destructor | Closes, destroys base state, and conditionally frees. |

## Evidence Notes

- IDA vtable entries at `0x0062d5ac` confirm `GetSize`, `GetPosition`, `Seek`, and `Read` are real virtual methods even though current active generated output leaves them in the disabled companion file. The position/seek/read cluster is documented at [UID:0001IV][0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods](by-memory/0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods.md).
- [UID:0003I1][StdioFileVtable](by-type/by-vtable/StdioFileVtable.md) is the exact source-local vtable child for this class. It splits the `StdioFile` table from the broader [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md) ABI index and the mixed [UID:00026L][0x0062d5a8-0x0062d5f8.StdioFileStringIterReadOnlyData](by-memory/0x0062d5a8-0x0062d5f8.StdioFileStringIterReadOnlyData.md) memory page.
- IDA decompilation of [UID:0001IT][0x005820d0-0x005821c9.StdioFileOpen](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md) shows the cached size is copied from the stat buffer into `this[2]`, so generated text that names this placeholder `statBuffer_size` needs cleanup.
- 2026-05-26 IDA MCP recheck confirms all omitted disabled methods as real project-code virtual slots and confirms `Open` still copies local stat-buffer size into `this[2]`.
- IDA decompilation of `ReadRemaining` confirms the destination buffer pointer is freed twice before replacement allocation. Preserve this as binary behavior until a later rewrite pass makes an explicit source-level decision.
- Direct callers include startup logo/video loading, main-menu art loading, map `.cmp` loading, and the Miles file callback bridge in [UID:0000NV][SoundManager](by-file/SoundManager.md).
- 2026-06-12 A004 Batch297 live IDA MCP refresh confirmed the method-size map for constructor/open/close/tell/seek/size/read/raw-line/string-line/deleting-destructor, vtable install/restore refs at `0x0058207f`, `0x005820a6`, and `0x005824a9`, and `Open` field writes to `this[1]` (`FILE*`) and `this[2]` (cached `_wstat` size). This raises confidence above the strict parent gate for [UID:0003H2][StdioFileLayout](by-type/by-struct/StdioFileLayout.md).
- 2026-06-29 B006 UID0001IQ implementation refresh superseded the old `95/95` blank-code blocker for the constructor. Under current `by-structure.md`, UID0001IQ is reconstructable, routes through this class to [UID:0000O9][StdioFile](by-file/StdioFile.md) / `auto-generated/NexusTK/util/StdioFile.cpp`, and clears the combined-score/emitter C++ gate. Source C++ must not manually call `sub_4F4A80` or assign the vtable; the base-construction chain and compiler vtable install account for those observed writes. The 2026-07-01 B010 callback extends that source-ready treatment to the accepted StdioFile sibling emitters. `FileIO`, `File`, `PathUtil`, caller pages, and `SoundManager` remain context/consumers rather than direct constructor or method owners.
- 2026-07-01 B010 UID0000O9 implementation refresh supersedes the remaining family-wide empty-emitter blockers. The class declaration/prototype block is now appropriate from method set, vtable order, layout, and File interface evidence. Exact public typedef spellings and `Tell` versus `GetPosition` remain confidence caps, not blockers for formal first-draft C++.

## Cross-References

- [UID:0000O9][StdioFile](by-file/StdioFile.md)
- [UID:0000JD][FileIO](by-file/FileIO.md)
- [UID:00004V][File](by-class/File.md)
- [UID:0003I1][StdioFileVtable](by-type/by-vtable/StdioFileVtable.md)
- [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md)
- [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md)
- [UID:0003H2][StdioFileLayout](by-type/by-struct/StdioFileLayout.md)
- [UID:0001IR][0x00582070-0x005824f6.StdioFile](by-memory/0x00582070-0x005824f6.StdioFile.md)
- [UID:0001IT][0x005820d0-0x005821c9.StdioFileOpen](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md)
- [UID:0001IV][0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods](by-memory/0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods.md)
- [UID:00019F][0x004f5ad0-0x004f5ad4.StdioFileGetSize](by-memory/0x004f5ad0-0x004f5ad4.StdioFileGetSize.md)
- [UID:0000V6][PathExistsViaStat_00582460](by-item/PathExistsViaStat_00582460.md)
- [UID:0000TU][0x0057b630-0x0057b72b.AILFileOpenCallback](by-memory/0x0057b630-0x0057b72b.AILFileOpenCallback.md)

## Changes

- 2026-07-01 B010 UID0000O9 empty-emitter family implementation:
  - Before: `88/86`, no formal class-shell C++, and no emitter ordering for declaration-before-method output.
  - After: `90/89`, `EMITTER_POSITION_OPTIONAL:0`, and formal first-draft class declaration/prototype C++ with VC6/VC7-safe `StringBaseA`/`StringBaseW` typedefs, current virtual order, non-virtual wide/read-remaining helpers, `m_fileHandle`, `m_fileSize`, and an explicit `[[CHILDREN]]` insertion point.
  - Summary/evidence: class shell now reflects the accepted StdioFile family route and preserves key caveats: `Open` caller return ignored, `Close` leaves the handle value untouched, line-read byte/EOF details, wide helper unconditional conversion/assignment, duplicate `ReadRemaining` free, and inferred string/Tell naming.
- 2026-06-29 B006 UID0001IQ constructor implementation:
  - Scores unchanged for this class.
  - Summary/evidence: [UID:0001IQ][0x00582070-0x0058209a.StdioFileConstructor](by-memory/0x00582070-0x0058209a.StdioFileConstructor.md) is now source-ready at `90/93` with formal `StdioFile::StdioFile()` C++ that zeroes inferred `m_fileHandle` and `m_fileSize`. Current MCP session `3fa0535f` reconfirmed exact constructor range/bytes/padding, one-block/no-string/no-constant body, base-constructor callee, five callers, `0x0058207f` vptr install, field provenance through `Open`/`GetSize`/stream consumers, and rejected no-code/manual-vtable/caller/FileIO/PathUtil alternatives.
- 2026-05-31:
  - Before: `RECONSTRUCTABLE` metadata was blank.
  - After: marked `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP confirms the `StdioFile` constructor, vtable install/restore sites, CRT `FILE*` field use, cached size field, and stream virtual methods; no parent/code was attached at that time because final source text was still gated by older `95+` policy language.

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `88`, confidence `80`.
- Evidence: the page documents role, layout, vtables, constructor/destructor/open/close/position/seek/read/line/remaining/destructor methods, disabled-but-real virtual slots, caller evidence, and binary-behavior caveats; confidence remains capped by exact original file split and rewrite decisions around `ReadRemaining`.

- 2026-06-06 parent-chain sync:
  - What existed before: the class was reconstructable and strong enough for attachment, but `AUTOGEN_PARENT_UID` was blank while child method pages pointed at this class.
  - Changed to: parent [UID:0000O9][StdioFile](by-file/StdioFile.md).
  - Summary/evidence: [UID:0000O9][StdioFile](by-file/StdioFile.md) recorded the exact constructor, executable island, virtual position/read methods, line-read helpers, vtable, layout, and caller evidence at `82/84`, so the class-to-file chain satisfied the 80/80 gate. The then-current note left C++ blank under an older `95/95` final-source gate; that gate is superseded for UID0001IQ by the 2026-06-29 B006 constructor implementation and for accepted sibling emitters by the 2026-07-01 B010 callback.
- 2026-06-12 A004 Batch 297 layout-parent refresh:
  - Before: confidence remained `80`, which blocked strict 85/85 routing for the exact `StdioFile` layout child.
  - After: confidence raised to `86` with score `88/86`; [UID:0003H2][StdioFileLayout](by-type/by-struct/StdioFileLayout.md) now routes here as its direct class parent.
  - Summary/evidence: live IDA MCP reconfirmed the method-size map, vtable refs, concrete `Open` field writes, and caller set; source-file split remains a caveat, but class ownership and layout are now above the strict gate.
- 2026-06-12 A004 Batch 319 vtable split sync:
  - Scores remain `88/86`.
  - Added [UID:0003I1][StdioFileVtable](by-type/by-vtable/StdioFileVtable.md) as the exact source-local vtable child for this class; [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md) is now only the non-emitting shared File/DATFile/StdioFile slot-layout index.
  - Evidence: live IDA MCP reconfirmed `??_7StdioFile@@6B@`, concrete stream slot target sizes, constructor/destructor/deleting-destructor refs, and the `0x0062d5d8` successor whitespace boundary.
