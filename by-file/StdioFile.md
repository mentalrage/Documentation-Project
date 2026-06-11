*** UID:0000O9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# StdioFile

## Status

- Confidence: strong for local-file implementation behavior; medium for exact split from [UID:0000JB][File](by-file/File.md).
- Proposed module: `NexusTK/util/StdioFile.cpp`, or folded into a compact `NexusTK/util/FileIO.cpp` if later source-structure evidence favors one file.
- Umbrella doc: [UID:0000JD][FileIO](by-file/FileIO.md)
- Current recovered source: `source-3/simroot_v2/class_StdioFile.cpp`
- Main memory docs: [UID:0001IR][0x00582070-0x005824f6.StdioFile](by-memory/0x00582070-0x005824f6.StdioFile.md), [UID:0001IT][0x005820d0-0x005821c9.StdioFileOpen](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md), [UID:0001IV][0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods](by-memory/0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods.md), and [UID:00019F][0x004f5ad0-0x004f5ad4.StdioFileGetSize](by-memory/0x004f5ad0-0x004f5ad4.StdioFileGetSize.md)
- Type docs: [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md), [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md)

## File Role

`StdioFile.cpp` should own the concrete filesystem-backed `File` implementation. It opens wide paths through C runtime stat/open calls, stores a `FILE*`, caches file size, and implements the file vtable slots for close, tell, seek, size, read, and line reads.

2026-05-31 IDA MCP recheck confirms the constructor/open/read/helper island at `0x00582070-0x00582495`, the scalar deleting destructor at `0x005824a0`, the non-contiguous `GetSize` virtual at `0x004f5ad0`, and the `StdioFile` vtable at `0x0062d5ac`. The vtable fills the same operation slots that `File` leaves pure virtual, which supports a utility-layer concrete file-stream source rather than a caller-owned helper.

2026-06-06 parent-chain review confirms this file now clears the class attachment gate: [UID:0000E6][StdioFile](by-class/StdioFile.md) is `88/80`, this file is `82/84`, and the linked method pages document the constructor/destructor/open/close/position/read/read-line/read-remaining/destructor family strongly enough to stage `StdioFile` under this `NexusTK/util/` source root. The remaining caveat is exact standalone `StdioFile.cpp` versus compact `FileIO.cpp` grouping, not ownership or runtime behavior.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:0000E6][StdioFile](by-class/StdioFile.md) | [UID:0001IR][0x00582070-0x005824f6.StdioFile](by-memory/0x00582070-0x005824f6.StdioFile.md), plus [UID:00019F][0x004f5ad0-0x004f5ad4.StdioFileGetSize](by-memory/0x004f5ad0-0x004f5ad4.StdioFileGetSize.md) | Local-file reader implementation. |
| [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md) | `0x0062d5ac-0x0062d5d8` | Concrete virtual slots over the `File` contract. |
| [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md) | size `0x0c` | `FILE*` handle at `+0x04`, cached size at `+0x08`. |

## Method Evidence

The source-file root is backed by the following exact child and support pages:

- [UID:0001IQ][0x00582070-0x0058209a.StdioFileConstructor](by-memory/0x00582070-0x0058209a.StdioFileConstructor.md) records exact constructor bytes, vtable store, base constructor call, field clears, and five static construction callers.
- [UID:0001IR][0x00582070-0x005824f6.StdioFile](by-memory/0x00582070-0x005824f6.StdioFile.md) covers the executable island and child method split.
- [UID:0001IV][0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods](by-memory/0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods.md) covers the virtual tell/seek/read methods and their vtable slots.
- [UID:0001IW][0x00582250-0x005822c1.StdioFileReadLineChars](by-memory/0x00582250-0x005822c1.StdioFileReadLineChars.md) and [UID:0002RH][0x00582380-0x00582405.StdioFileReadLineWideHelper](by-memory/0x00582380-0x00582405.StdioFileReadLineWideHelper.md) document line-read helpers and wrapper behavior.
- [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md) and [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md) tie the virtual slot order and 12-byte object layout to the concrete file-stream implementation.

## Boundary Notes

- [UID:0000MI][PathUtil](by-file/PathUtil.md) may stay in `StdioFile.cpp` if final migration favors a small file-I/O module.
- Keep Miles AIL file callbacks with [UID:0000NV][SoundManager](by-file/SoundManager.md); they instantiate file readers but are audio callback bridge code.
- Keep [UID:0000IN][DATFile](by-file/DATFile.md) under `archive/`.

## Cross-References

- [UID:0000JD][FileIO](by-file/FileIO.md)
- [UID:0000E6][StdioFile](by-class/StdioFile.md)
- [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md)
- [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md)
- [UID:0001IR][0x00582070-0x005824f6.StdioFile](by-memory/0x00582070-0x005824f6.StdioFile.md)
- [UID:0001IT][0x005820d0-0x005821c9.StdioFileOpen](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md)
- [UID:0001IV][0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods](by-memory/0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods.md)
- [UID:00019F][0x004f5ad0-0x004f5ad4.StdioFileGetSize](by-memory/0x004f5ad0-0x004f5ad4.StdioFileGetSize.md)
- [UID:0000MI][PathUtil](by-file/PathUtil.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `76` and confidence to `78`.
  - Evidence: document captures concrete file-stream role, proposed contents, vtable/layout refs, File/DAT/audio boundaries, and cross-references; completion remains lower because method behavior, callers, and reconstructed C++ shape are only summarized.
- 2026-05-31 reconstruction path and IDA recheck:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, scores were `76/78`, and the module path used `util/StdioFile.cpp` without an explicit generated root.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`, scores `78/82`, and proposed module `NexusTK/util/StdioFile.cpp`.
  - Summary/evidence: IDA MCP reconfirmed the main `StdioFile` island, `0x004f5ad0` vtable-only `GetSize`, `0x0062d5ac` concrete vtable slot map, and caller spread from startup/menu/map/audio paths. C++ reconstruction remains blank because the per-method source rewrite and final split from `File.cpp` are not yet complete enough for final-source-quality code.
- 2026-06-06 parent-chain evidence sync:
  - What existed before: this file was scored `78/82`, leaving the attached [UID:0000E6][StdioFile](by-class/StdioFile.md) class parent chain below the documented file-root gate.
  - Changed to: completion `82`, confidence `84`.
  - Summary/evidence: the constructor, executable island, virtual position/read cluster, line-read helpers, vtable, layout, and caller evidence now justify this as the active `NexusTK/util/` root for the `StdioFile` class while preserving the final `StdioFile.cpp` versus compact `FileIO.cpp` split caveat. No reconstruction C++ was added.
