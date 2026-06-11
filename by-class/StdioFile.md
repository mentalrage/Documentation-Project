*** UID:0000E6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000O9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# StdioFile

## Status

- Confidence: strong for class behavior, medium for exact original file split.
- Proposed path: [UID:0000O9][StdioFile](by-file/StdioFile.md), under the [UID:0000JD][FileIO](by-file/FileIO.md) utility layer
- Parent attachment: [UID:0000O9][StdioFile](by-file/StdioFile.md); both the class and file root now clear the 80/80 attachment gate.
- Current Wave3 file: `class_StdioFile.cpp`
- Main address evidence: [UID:0001IR][0x00582070-0x005824f6.StdioFile](by-memory/0x00582070-0x005824f6.StdioFile.md), [UID:0001IT][0x005820d0-0x005821c9.StdioFileOpen](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md), [UID:0001IV][0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods](by-memory/0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods.md), plus [UID:00019F][0x004f5ad0-0x004f5ad4.StdioFileGetSize](by-memory/0x004f5ad0-0x004f5ad4.StdioFileGetSize.md)
- Size/layout: 12 bytes; `File` base at `+0`, `FILE*` handle at `+4`, cached file size at `+8`. See [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md).
- Vtable/type evidence: [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md)

## Role

`StdioFile` is the loose-filesystem implementation of the [UID:00004V][File](by-class/File.md) stream interface. It opens a wide path in binary-read mode, tracks the total file size from `_wstat`, and exposes virtual read/seek/line-reading methods to callers that can also work with [UID:00003G][DATFile](by-class/DATFile.md).

## Confirmed Methods

| Address | Method | Notes |
| --- | --- | --- |
| [UID:0001IQ][0x00582070-0x0058209a.StdioFileConstructor](by-memory/0x00582070-0x0058209a.StdioFileConstructor.md) | constructor | Initializes `File`/`LObject`, installs the `StdioFile` vtable, clears handle and size. |
| [UID:0001IS][0x005820a0-0x005820c7.StdioFileDestructor](by-memory/0x005820a0-0x005820c7.StdioFileDestructor.md) | destructor | Closes the handle if present, restores `File` vtable, destroys `LObject`. |
| [UID:0001IT][0x005820d0-0x005821c9.StdioFileOpen](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md) | `Open` | Calls `_wstat`, opens with `rb`, stores handle and stat size, throws [UID:00004X][FileError](by-class/FileError.md) on failure. |
| [UID:0001IU][0x005821d0-0x005821f7.StdioFileClose](by-memory/0x005821d0-0x005821f7.StdioFileClose.md) | `Close` | Closes the handle and clears cached size; returns close success. |
| [UID:0001IV][0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods](by-memory/0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods.md) | `GetPosition` | Returns `ftell(handle)`. |
| [UID:0001IV][0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods](by-memory/0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods.md) | `Seek` | Returns whether `fseek(handle, offset, origin)` succeeded. |
| [UID:00019F][0x004f5ad0-0x004f5ad4.StdioFileGetSize](by-memory/0x004f5ad0-0x004f5ad4.StdioFileGetSize.md) | `GetSize` | Returns cached size at offset `+8`. |
| [UID:0001IV][0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods](by-memory/0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods.md) | `Read` | Reads bytes through `fread(buffer, 1, count, handle)`. |
| [UID:0001IW][0x00582250-0x005822c1.StdioFileReadLineChars](by-memory/0x00582250-0x005822c1.StdioFileReadLineChars.md) | `ReadLineChars` | Reads into caller buffer until CR/LF/EOF/limit. |
| [UID:0001IX][0x005822d0-0x00582379.StdioFileReadLine](by-memory/0x005822d0-0x00582379.StdioFileReadLine.md) | `ReadLine` | Builds an `LString` line with CR/LF handling. |
| [UID:0001IY][0x00582410-0x00582459.StdioFileReadRemaining](by-memory/0x00582410-0x00582459.StdioFileReadRemaining.md) | `ReadRemaining` | Allocates a buffer for bytes from current position to EOF and reads them. |
| [UID:0001J0][0x005824a0-0x005824f6.StdioFileScalarDeletingDestructor](by-memory/0x005824a0-0x005824f6.StdioFileScalarDeletingDestructor.md) | scalar deleting destructor | Closes, destroys base state, and conditionally frees. |

## Evidence Notes

- IDA vtable entries at `0x0062d5ac` confirm `GetSize`, `GetPosition`, `Seek`, and `Read` are real virtual methods even though current active generated output leaves them in the disabled companion file. The position/seek/read cluster is documented at [UID:0001IV][0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods](by-memory/0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods.md).
- IDA decompilation of [UID:0001IT][0x005820d0-0x005821c9.StdioFileOpen](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md) shows the cached size is copied from the stat buffer into `this[2]`, so generated text that names this placeholder `statBuffer_size` needs cleanup.
- 2026-05-26 IDA MCP recheck confirms all omitted disabled methods as real project-code virtual slots and confirms `Open` still copies local stat-buffer size into `this[2]`.
- IDA decompilation of `ReadRemaining` confirms the destination buffer pointer is freed twice before replacement allocation. Preserve this as binary behavior until a later rewrite pass makes an explicit source-level decision.
- Direct callers include startup logo/video loading, main-menu art loading, map `.cmp` loading, and the Miles file callback bridge in [UID:0000NV][SoundManager](by-file/SoundManager.md).

## Cross-References

- [UID:0000O9][StdioFile](by-file/StdioFile.md)
- [UID:0000JD][FileIO](by-file/FileIO.md)
- [UID:00004V][File](by-class/File.md)
- [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md)
- [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md)
- [UID:0001IR][0x00582070-0x005824f6.StdioFile](by-memory/0x00582070-0x005824f6.StdioFile.md)
- [UID:0001IT][0x005820d0-0x005821c9.StdioFileOpen](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md)
- [UID:0001IV][0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods](by-memory/0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods.md)
- [UID:00019F][0x004f5ad0-0x004f5ad4.StdioFileGetSize](by-memory/0x004f5ad0-0x004f5ad4.StdioFileGetSize.md)
- [UID:0000V6][PathExistsViaStat_00582460](by-item/PathExistsViaStat_00582460.md)
- [UID:0000TU][AILFileOpenCallback_0057B630](by-item/AILFileOpenCallback_0057B630.md)

## Changes

- 2026-05-31:
  - Before: `RECONSTRUCTABLE` metadata was blank.
  - After: marked `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP confirms the `StdioFile` constructor, vtable install/restore sites, CRT `FILE*` field use, cached size field, and stream virtual methods; no parent/code was attached because final source text is not yet at the 95+ gate.

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `88`, confidence `80`.
- Evidence: the page documents role, layout, vtables, constructor/destructor/open/close/position/seek/read/line/remaining/destructor methods, disabled-but-real virtual slots, caller evidence, and binary-behavior caveats; confidence remains capped by exact original file split and rewrite decisions around `ReadRemaining`.

- 2026-06-06 parent-chain sync:
  - What existed before: the class was reconstructable and strong enough for attachment, but `AUTOGEN_PARENT_UID` was blank while child method pages pointed at this class.
  - Changed to: parent [UID:0000O9][StdioFile](by-file/StdioFile.md).
  - Summary/evidence: [UID:0000O9][StdioFile](by-file/StdioFile.md) now records the exact constructor, executable island, virtual position/read methods, line-read helpers, vtable, layout, and caller evidence at `82/84`, so the class-to-file chain satisfies the 80/80 gate. C++ remains blank under the 95/95 final-source gate.
