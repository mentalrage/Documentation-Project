*** UID:0000JB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# File

## Status

- Confidence: strong for the abstract file interface; medium for whether original source was split from [UID:0000O9][StdioFile](by-file/StdioFile.md).
- Proposed module: `NexusTK/util/File.cpp`, or folded into a compact `NexusTK/util/FileIO.cpp` if later source-structure evidence favors one file.
- Umbrella doc: [UID:0000JD][FileIO](by-file/FileIO.md)
- Current recovered source: `source-3/simroot_v2/class_File.cpp`
- Type docs: [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md), [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md)

## File Role

`File.cpp` is the abstract `LObject`-derived stream interface used by concrete file readers. It should own the base vtable contract and scalar deleting destructor at `0x0049d390-0x0049d3cd`.

Do not place DAT archive parsing here. [UID:0000IN][DATFile](by-file/DATFile.md) implements the same file-like surface over packed archive entries and belongs under `archive/`.

The interface contract is now explicit: IDA shows `File` slots `+0x0c` through `+0x28` are pure virtual and are filled by both [UID:0000IN][DATFile](by-file/DATFile.md) and [UID:0000O9][StdioFile](by-file/StdioFile.md). This makes `File.h` the common declaration point for open, close, tell/position, seek, size, read, and line-read methods, while the implementation files remain split by backing store.

2026-05-31 IDA MCP recheck confirms `0x0049d390-0x0049d3ce` as the base destructor body referenced by the `File` vtable at `0x006188e4`. That vtable has the base destructor/runtime slots followed by pure virtual operation slots from `+0x0c` through `+0x28`, which supports keeping the abstract interface in a utility-layer source file rather than under archive, audio, map, or any concrete caller module.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:00004V][File](by-class/File.md) | `0x0049d390-0x0049d3cd` | Abstract file/stream base destructor and vtable contract. |
| [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md) | `0x006188e4-0x00618910` | Base destructor plus pure virtual file operation slots. |
| [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md) | size `0x08` | Vtable at `+0x00` and a concrete-implementation handle word at `+0x04`; final base-field name remains open. |

## Cross-References

- [UID:0000JD][FileIO](by-file/FileIO.md)
- [UID:00004V][File](by-class/File.md)
- [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md)
- [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md)
- [UID:00012I][0x0049d390-0x0049d3cd.FileBaseDestructor](by-memory/0x0049d390-0x0049d3cd.FileBaseDestructor.md)
- [UID:0000O9][StdioFile](by-file/StdioFile.md)
- [UID:0000IN][DATFile](by-file/DATFile.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:80`.
  - Summary/evidence: abstract stream interface role, vtable/layout contract, DAT/StdioFile boundary, proposed placement, and core cross-references are documented; completion is moderate because this is a small base-interface page and detailed implementation behavior lives in concrete file pages.
- 2026-05-31 reconstruction path and IDA recheck:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, scores were `80/80`, and the module path used `util/File.cpp` without an explicit generated root.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`, scores `82/84`, and proposed module `NexusTK/util/File.cpp`.
  - Summary/evidence: IDA MCP reconfirmed the `0x0049d390-0x0049d3ce` destructor body, `File` vtable xref, and pure virtual operation slots, matching the existing `proposed-source-tree.md` utility placement. C++ reconstruction remains blank because the original one-file versus split-file boundary with `StdioFile` is still not fully proven.
