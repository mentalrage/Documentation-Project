*** UID:0000JD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# FileIO

## Status

- Confidence: strong for class responsibility and utility-layer boundaries, medium-high for exact original file split.
- Proposed modules: `util/File.cpp`, `util/StdioFile.cpp`, and possibly `util/PathUtil.cpp`
- Projected reconstruction path: `NexusTK/util/FileIO.cpp`
- Recovered source views: `class_File.cpp`, `class_StdioFile.cpp`, and `PathExistsViaStat_00582460.cpp`
- Main classes: [UID:00004V][File](by-class/File.md) and [UID:0000E6][StdioFile](by-class/StdioFile.md)
- Main memory docs: [UID:00012I][0x0049d390-0x0049d3cd.FileBaseDestructor](by-memory/0x0049d390-0x0049d3cd.FileBaseDestructor.md), [UID:0001IR][0x00582070-0x005824f6.StdioFile](by-memory/0x00582070-0x005824f6.StdioFile.md), [UID:0001IT][0x005820d0-0x005821c9.StdioFileOpen](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md), [UID:0001IV][0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods](by-memory/0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods.md), [UID:00019F][0x004f5ad0-0x004f5ad4.StdioFileGetSize](by-memory/0x004f5ad0-0x004f5ad4.StdioFileGetSize.md), [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md), and [UID:00022K][0x004b81f0-0x004b821e.FileExists](by-memory/0x004b81f0-0x004b821e.FileExists.md) as a [UID:0000MI][PathUtil](by-file/PathUtil.md)-owned file-existence helper
- Type docs: [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md), [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md)
- Evidence basis: live IDA MCP lookup/decompilation/xref checks on 2026-05-24 through 2026-05-26, with recovered source views used only as naming candidates.

## File Role

This utility layer provides the generic `File` stream interface and the loose-filesystem implementation used when the client reads files outside the packed DAT archives. It should stay separate from [UID:0000IN][DATFile](by-file/DATFile.md): `DATFile` implements the same file-like surface over mapped archive entries, while `StdioFile` implements it over C `FILE*` streams.

The strongest reconstruction is a small `File.cpp` for the abstract base and a neighboring `StdioFile.cpp` for the stdio-backed implementation. A flat late-1999/early-2000s Visual C++ project could also have placed both in one `File.cpp`; for the current structured tree, keep them under `util/` rather than `archive/`, `map/`, or `audio/`.

`StdioFile`, `PathExistsViaStat`, and `FileExists` consume the process-wide [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md), but they do not own it. The `_wfopen` pointer at `0x0069be14` and `_wstat64i32` pointer at `0x0069be18` are initialized by [UID:0000ML][PlatformApi](by-file/PlatformApi.md) at [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md).

## Proposed Contents

| Entity | Address evidence | Proposed placement | Notes |
| --- | --- | --- | --- |
| `File` | `0x0049d390-0x0049d3cd`; vtable at `0x006188e4` | `util/File.cpp` | Abstract `LObject`-derived stream base. Slots after the base runtime methods are pure virtual. |
| `StdioFile` | [UID:0001IR][0x00582070-0x005824f6.StdioFile](by-memory/0x00582070-0x005824f6.StdioFile.md), plus [UID:00019F][0x004f5ad0-0x004f5ad4.StdioFileGetSize](by-memory/0x004f5ad0-0x004f5ad4.StdioFileGetSize.md) | `util/StdioFile.cpp` | Concrete local-file reader with `FILE*` at offset `+4` and cached file size at offset `+8`. |
| `PathExistsViaStat` | [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md) | `util/PathUtil.cpp` | Shared `_wstat`-based wide-path existence check. |
| `FileExists` | [UID:00022K][0x004b81f0-0x004b821e.FileExists](by-memory/0x004b81f0-0x004b821e.FileExists.md) | `util/PathUtil.cpp` | Shared `_wfopen`/`fclose` wide-path existence check used by archive-manager and monster-archive discovery paths; not PlatformApi-owned despite using `dword_69BE14`. |
| Miles AIL file callbacks | `0x0057b630-0x0057b7e7` | [UID:0000NV][SoundManager](by-file/SoundManager.md) | Audio-local callback bridge that creates `DATFile` or `StdioFile` readers for Miles. Keep with audio. |

## Evidence Notes

- IDA shows the `File` vtable starts with `File::ScalarDeletingDestructor`, inherited runtime/no-op methods, then pure virtual entries for open/close/tell/seek/size/read/line-read behavior.
- IDA shows the `StdioFile` vtable at `0x0062d5ac` implements the same virtual slots with `Open`, `Close`, `GetPosition`, `Seek`, `GetSize`, `Read`, `ReadLine`, and `ReadLineChars`.
- 2026-05-25 IDA vtable/xref recheck now records the exact shared slot map in [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md), including the matching `DATFile` vtable at `0x00618924`.
- Recovered disabled `StdioFile` output contains real vtable methods (`GetSize`, `GetPosition`, `Seek`, and `Read`) that other source views omitted. Treat those methods as real until ownership is refreshed.
- `StdioFile::Open` calls the imported `_wstat64i32` dispatch pointer at `0x0069be18`, opens the path with the `_wfopen` dispatch pointer at `0x0069be14`, stores the `FILE*`, stores the stat size field, and throws [UID:00004X][FileError](by-class/FileError.md) on stat/open failure. The stat-size placeholder is documented at [UID:0001IT][0x005820d0-0x005821c9.StdioFileOpen](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md).
- 2026-05-26 IDA MCP recheck keeps the omitted vtable methods as live project code, not ignored/runtime code. `PathExistsViaStat` remains a shared utility with callers in startup/logo, application startup, map loading, and the Miles AIL file-open callback.
- 2026-06-10 B001-022 IDA recheck assigns [UID:00022K][0x004b81f0-0x004b821e.FileExists](by-memory/0x004b81f0-0x004b821e.FileExists.md) to [UID:0000MI][PathUtil](by-file/PathUtil.md). Its caller set is `_DATFileMgr::LoadDATFileIndex` twice and `MonsterImageLib::LoadMonsterArchives` once, so DAT/monster ownership is only caller-local; PlatformApi ownership is only the dispatch slot. The helper is paired with [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md), while `StdioFile::Open` remains the object-stateful file-stream method.
- `StdioFile::ReadRemaining` is a direct convenience method used by startup media and map-file paths. IDA confirms the duplicated free of the destination buffer pointer before allocation; do not silently remove it during source reconstruction without a behavior decision.
- `PathExistsViaStat` has broad callers from startup-logo, application startup, main-menu art loading, map `.cmp` loading, and the Miles AIL file-open callback. That spread supports a utility placement.

## Ownership Boundaries

Keep [UID:0000IN][DATFile](by-file/DATFile.md) in `archive/DATFile.cpp`: it is a concrete archive-backed reader and depends on `DATFileMgr` lookup/index state. Keep [UID:0000J5][Error](by-file/Error.md) in `util/Error.cpp`: `StdioFile` and `DATFile` construct it, but the error wrapper is not owned by file I/O. Keep Miles AIL file callbacks in [UID:0000NV][SoundManager](by-file/SoundManager.md), because IDA shows they are registered through `AIL_set_file_callbacks` inside `SoundManager::ReinitializeAudioDriver`. Keep [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md) in `platform/PlatformApi.cpp`, because it is shared process/platform compatibility state rather than a file-stream field.

## Cross-References

- [UID:00004V][File](by-class/File.md)
- [UID:0000E6][StdioFile](by-class/StdioFile.md)
- [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md)
- [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md)
- [UID:0001IT][0x005820d0-0x005821c9.StdioFileOpen](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md)
- [UID:0001IV][0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods](by-memory/0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods.md)
- [UID:00022K][0x004b81f0-0x004b821e.FileExists](by-memory/0x004b81f0-0x004b821e.FileExists.md)
- [UID:0000IN][DATFile](by-file/DATFile.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0000NV][SoundManager](by-file/SoundManager.md)
- [UID:0000V6][PathExistsViaStat_00582460](by-item/PathExistsViaStat_00582460.md)
- [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md)
- [UID:0000TU][AILFileOpenCallback_0057B630](by-item/AILFileOpenCallback_0057B630.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-06-10 B001-022 PathUtil split clarification:
  - Before: `CONFIDENCE:84`, with [UID:00022K][0x004b81f0-0x004b821e.FileExists](by-memory/0x004b81f0-0x004b821e.FileExists.md) listed as unresolved between PathUtil, FileIO, and nearby file helpers.
  - Changed to: `CONFIDENCE:85`; `FileExists` and `PathExistsViaStat` are documented as [UID:0000MI][PathUtil](by-file/PathUtil.md)-owned helpers inside the broader FileIO utility layer.
  - Summary/evidence: live IDA MCP reconfirmed `FileExists` as a free boolean existence probe with archive/monster callers, no stream object state, and `_wfopen` dispatch dependency. The direct parent is PathUtil; this page remains an umbrella rather than the narrow autogen parent.
- 2026-06-08 A006 Batch 118 parent/source candidate update:
  - Before: `COMPLETION:86`, `CONFIDENCE:80`.
  - Changed to: `COMPLETION:87`, `CONFIDENCE:84`.
  - Summary/evidence: added the [UID:00022K][0x004b81f0-0x004b821e.FileExists](by-memory/0x004b81f0-0x004b821e.FileExists.md) candidate and documented why it is file/path utility evidence rather than PlatformApi, DATFileMgr, or MonsterImageLib ownership. Confidence remains below the strict parent gate because the final `PathUtil.cpp` versus `StdioFile.cpp`/`FileIO.cpp` split is still unresolved.
- 2026-06-05: Assigned projected reconstruction path `NexusTK/util/` to resolve the by-file generated-root coverage error.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the document and proposed source tree place the file-stream utility layer under `util/`.
  - After: set the validator path to `NexusTK/util/` without changing completion/confidence or writing reconstruction C++.
  - Evidence: `by-project-structure/proposed-source-tree.md` groups `File.cpp`, `StdioFile.cpp`, and `PathUtil.cpp` under `util/`, and live IDA MCP lookup on 2026-06-05 confirms the `StdioFile` anchor at `0x00582070` as a real function of size `0x2a`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:80`.
  - Summary/evidence: file-stream layer role, proposed `File`/`StdioFile`/path utility split, DAT/audio/platform boundaries, vtable and WideApi evidence, ownership notes, and cross-references are documented; confidence remains at 80 because exact original source split is still uncertain.
