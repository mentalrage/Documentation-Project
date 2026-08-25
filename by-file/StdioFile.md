*** UID:0000O9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# StdioFile

## Status

- Confidence: strong for local-file implementation behavior and concrete layout ownership; medium-high for exact split from [UID:0000JB][File](by-file/File.md).
- Proposed module: `NexusTK/util/StdioFile.cpp`, or folded into a compact `NexusTK/util/FileIO.cpp` if later source-structure evidence favors one file.
- Umbrella doc: [UID:0000JD][FileIO](by-file/FileIO.md)
- Current recovered source: `source-3/simroot_v2/class_StdioFile.cpp`
- Main memory docs: [UID:0001IR][0x00582070-0x005824f6.StdioFile](by-memory/0x00582070-0x005824f6.StdioFile.md), [UID:0001IT][0x005820d0-0x005821c9.StdioFileOpen](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md), [UID:0001IV][0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods](by-memory/0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods.md), and [UID:00019F][0x004f5ad0-0x004f5ad4.StdioFileGetSize](by-memory/0x004f5ad0-0x004f5ad4.StdioFileGetSize.md)
- Type docs: [UID:0003I1][StdioFileVtable](by-type/by-vtable/StdioFileVtable.md), shared index [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md), [UID:0003H2][StdioFileLayout](by-type/by-struct/StdioFileLayout.md), and mixed index [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md)

## File Role

`StdioFile.cpp` should own the concrete filesystem-backed `File` implementation. It opens wide paths through C runtime stat/open calls, stores a `FILE*`, caches file size, and implements the file vtable slots for close, tell, seek, size, read, and line reads.

2026-05-31 IDA MCP recheck confirms the constructor/open/read/helper island at `0x00582070-0x00582495`, the scalar deleting destructor at `0x005824a0`, the non-contiguous `GetSize` virtual at `0x004f5ad0`, and the `StdioFile` vtable at `0x0062d5ac`. The vtable fills the same operation slots that `File` leaves pure virtual, which supports a utility-layer concrete file-stream source rather than a caller-owned helper.

2026-06-06 parent-chain review staged this file under the utility source root, and the 2026-06-12 Batch297 refresh raises the chain to the strict gate: [UID:0000E6][StdioFile](by-class/StdioFile.md) is now `88/86`, this file is now `85/86`, and the linked method pages document the constructor/destructor/open/close/position/read/read-line/read-remaining/destructor family strongly enough to keep `StdioFile` under this `NexusTK/util/` source root. The remaining caveat is exact standalone `StdioFile.cpp` versus compact `FileIO.cpp` grouping, not ownership or runtime behavior.

2026-06-12 A004 Batch297 live IDA MCP refresh confirms this file now clears the strict `85/85` gate for concrete StdioFile ownership. The check reconfirmed the constructor/open/close/tell/seek/size/read/raw-line/string-line/deleting-destructor sizes, vtable refs at `0x0058207f`, `0x005820a6`, and `0x005824a9`, and `Open` stores to the `FILE*` and cached-size fields. The final standalone `StdioFile.cpp` versus compact `FileIO.cpp` split remains the main source-layout caveat.

2026-06-16 A002 live IDA MCP refresh in session `b001_mappane_0001AW_20260616` (`NexusTK.exe`, image base `0x00400000`) reconfirmed the same source-root boundary: constructor `0x00582070` size `0x2a`, `Open` `0x005820d0` size `0xf9`, `Close` `0x005821d0` size `0x27`, tell/seek/read slots at `0x00582200`/`0x00582210`/`0x00582230`, line-read helpers through `0x00582410`, `PathExistsViaStat` at `0x00582460`, deleting destructor `0x005824a0`, and vtable-only `GetSize` at `0x004f5ad0`. Function profiling again shows constructor callers in startup-logo/video, main-menu art, map `.cmp`, and Miles audio callback contexts, while `Open`/`ReadRemaining` callers stay in the startup/menu/map feature set. No evidence moved these bodies to a caller-owned source file.

2026-06-29 B006 UID0001IQ implementation refresh makes the constructor source-ready in this file route. Current MCP session `3fa0535f` reconfirmed `0x00582070-0x0058209a` as a 42-byte / `0x2a` one-block constructor, with exact body bytes, two leading and six trailing `0xcc` bytes, no strings/constants, one inherited base-constructor callee, five construction callers, `StdioFile` vtable install at `0x0058207f`, and field zeroing at `+0x04` and `+0x08`. The accepted formal constructor emits through the existing [UID:0000E6][StdioFile](by-class/StdioFile.md) -> [UID:0000O9] route as `StdioFile::StdioFile()` with `m_fileHandle = NULL` and `m_fileSize = 0`. The remaining standalone `StdioFile.cpp` versus compact `FileIO.cpp` caveat is a broader source-tree granularity question, not a no-code blocker for this constructor.

2026-07-01 B010 UID0000O9 empty-emitter callback clears the remaining StdioFile family source blockers through the existing `NexusTK/util/StdioFile.cpp` route. The pre-callback generated file header was `validator-command-id: 000000003278` / `validator-refreshed-at: 2026-07-01T04:40:06-04:00`; generated coverage showed 15 StdioFile emitters, one filled constructor, and 14 empty markers. The accepted route keeps [UID:0000O9] as the file root, [UID:0000E6][StdioFile](by-class/StdioFile.md) as class shell/contract, [UID:0001IR][0x00582070-0x005824f6.StdioFile](by-memory/0x00582070-0x005824f6.StdioFile.md) as aggregate index, and exact child pages as emitters. Rejected alternatives remain explicit: do not fold these children into [UID:0000JD][FileIO](by-file/FileIO.md), do not move them to [UID:0000MI][PathUtil](by-file/PathUtil.md), do not hand-author raw vtable/scalar-deleting wrapper bodies, and do not let adjacent `PathExistsViaStat` or consumer callsites own the StdioFile methods. Scores remain below final `95+` because the exact historical standalone-vs-compact util source split, `Tell`/`GetPosition` spelling, and public string typedef spelling are still inferred.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:0000E6][StdioFile](by-class/StdioFile.md) | [UID:0001IR][0x00582070-0x005824f6.StdioFile](by-memory/0x00582070-0x005824f6.StdioFile.md), plus [UID:00019F][0x004f5ad0-0x004f5ad4.StdioFileGetSize](by-memory/0x004f5ad0-0x004f5ad4.StdioFileGetSize.md) | Local-file reader implementation. |
| [UID:0003I1][StdioFileVtable](by-type/by-vtable/StdioFileVtable.md) / shared index [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md) | `0x0062d5ac-0x0062d5d8` | Concrete virtual slots over the `File` contract. |
| [UID:0003H2][StdioFileLayout](by-type/by-struct/StdioFileLayout.md) | size `0x0c` | `FILE*` handle at `+0x04`, cached size at `+0x08`; split from [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md). |

## Method Evidence

The source-file root is backed by the following exact child and support pages:

- [UID:0001IQ][0x00582070-0x0058209a.StdioFileConstructor](by-memory/0x00582070-0x0058209a.StdioFileConstructor.md) is source-ready at `90/93`; it records exact constructor bytes, vtable store, base constructor call, field clears, five static construction callers, and now emits formal first-draft `StdioFile::StdioFile()` C++ that zeroes inferred `m_fileHandle` and `m_fileSize`.
- [UID:0001IR][0x00582070-0x005824f6.StdioFile](by-memory/0x00582070-0x005824f6.StdioFile.md) covers the executable island and child method split.
- [UID:0001IV][0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods](by-memory/0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods.md) covers the virtual tell/seek/read methods and their vtable slots.
- [UID:0001IW][0x00582250-0x005822c1.StdioFileReadLineChars](by-memory/0x00582250-0x005822c1.StdioFileReadLineChars.md) and [UID:0002RH][0x00582380-0x00582405.StdioFileReadLineWideHelper](by-memory/0x00582380-0x00582405.StdioFileReadLineWideHelper.md) document line-read helpers and wrapper behavior.
- [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md), [UID:0003H2][StdioFileLayout](by-type/by-struct/StdioFileLayout.md), and [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md) tie the virtual slot order and 12-byte object layout to the concrete file-stream implementation.
- 2026-07-01 source-ready additions: [UID:00019F][0x004f5ad0-0x004f5ad4.StdioFileGetSize](by-memory/0x004f5ad0-0x004f5ad4.StdioFileGetSize.md), [UID:0001IS][0x005820a0-0x005820c7.StdioFileDestructor](by-memory/0x005820a0-0x005820c7.StdioFileDestructor.md), [UID:0001IT][0x005820d0-0x005821c9.StdioFileOpen](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md), [UID:0001IU][0x005821d0-0x005821f7.StdioFileClose](by-memory/0x005821d0-0x005821f7.StdioFileClose.md), [UID:0001IV][0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods](by-memory/0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods.md), [UID:0001IW][0x00582250-0x005822c1.StdioFileReadLineChars](by-memory/0x00582250-0x005822c1.StdioFileReadLineChars.md), [UID:0001IX][0x005822d0-0x00582379.StdioFileReadLine](by-memory/0x005822d0-0x00582379.StdioFileReadLine.md), [UID:0002RH][0x00582380-0x00582405.StdioFileReadLineWideHelper](by-memory/0x00582380-0x00582405.StdioFileReadLineWideHelper.md), and [UID:0001IY][0x00582410-0x00582459.StdioFileReadRemaining](by-memory/0x00582410-0x00582459.StdioFileReadRemaining.md) now carry formal first-draft C++; [UID:0001IR][0x00582070-0x005824f6.StdioFile](by-memory/0x00582070-0x005824f6.StdioFile.md), [UID:0003H2][StdioFileLayout](by-type/by-struct/StdioFileLayout.md), [UID:0003I1][StdioFileVtable](by-type/by-vtable/StdioFileVtable.md), and [UID:0001J0][0x005824a0-0x005824f6.StdioFileScalarDeletingDestructor](by-memory/0x005824a0-0x005824f6.StdioFileScalarDeletingDestructor.md) carry formal no-standalone-code comments. Required behavior caveats are preserved on their exact pages: `Open` caller return ignored, `Close` does not clear `m_fileHandle`, raw line-read low-byte `0xff`/limit behavior, ANSI first-read EOF no-assignment, wide helper unconditional conversion/assignment, and `ReadRemaining` duplicate delete/free before replacement allocation.

## Boundary Notes

- [UID:0000MI][PathUtil](by-file/PathUtil.md) is the current separate `NexusTK/util/PathUtil.cpp` owner for [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md) and [UID:00022K][0x004b81f0-0x004b821e.FileExists](by-memory/0x004b81f0-0x004b821e.FileExists.md). Folding those free path probes into `StdioFile.cpp` is retained only as a rejected historical compact-file theory.
- Keep Miles AIL file callbacks with [UID:0000NV][SoundManager](by-file/SoundManager.md); they instantiate file readers but are audio callback bridge code.
- Keep [UID:0000IN][DATFile](by-file/DATFile.md) under `archive/`.
- Source-quality blocker review on 2026-06-16 checked the live IDA function map, caller sets, vtable refs, [UID:0000JD][FileIO](by-file/FileIO.md), [UID:0000JB][File](by-file/File.md), and [UID:0000MI][PathUtil](by-file/PathUtil.md). The remaining blocker is only StdioFile's original file granularity: current evidence proves a utility-layer concrete stream owner, but not whether the original project emitted a standalone `StdioFile.cpp` or folded the `File`/`StdioFile` class implementation into a compact file-I/O source. It does not reopen PathUtil ownership for the free path probes. No IDA rename/comment/type change was made because the StdioFile names still need final-source review.
- UID0001IQ narrows the generated-output issue: `auto-generated/NexusTK/util/StdioFile.cpp` was a marker-only file with UID0001IQ as an empty emitter before the accepted callback. After target/file validation, that generated file should contain the `StdioFile::StdioFile()` body while unrelated sibling StdioFile methods may remain empty until their own source-quality callbacks. This does not change `FileIO` umbrella status, `PathUtil` ownership for path probes, or `SoundManager` ownership for Miles callback bridge code.

## Cross-References

- [UID:0000JD][FileIO](by-file/FileIO.md)
- [UID:0000E6][StdioFile](by-class/StdioFile.md)
- [UID:0003I1][StdioFileVtable](by-type/by-vtable/StdioFileVtable.md)
- [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md)
- [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md)
- [UID:0003H2][StdioFileLayout](by-type/by-struct/StdioFileLayout.md)
- [UID:0001IR][0x00582070-0x005824f6.StdioFile](by-memory/0x00582070-0x005824f6.StdioFile.md)
- [UID:0001IT][0x005820d0-0x005821c9.StdioFileOpen](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md)
- [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md)
- [UID:0001IV][0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods](by-memory/0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods.md)
- [UID:00019F][0x004f5ad0-0x004f5ad4.StdioFileGetSize](by-memory/0x004f5ad0-0x004f5ad4.StdioFileGetSize.md)
- [UID:0000MI][PathUtil](by-file/PathUtil.md)

## Changes

- 2026-07-24 B001 UID0001IZ support verification: preserved StdioFile ownership and scores, linked the exact adjacent PathUtil-owned target, and historicalized the old suggestion that free path probes might fold into `StdioFile.cpp`. StdioFile's own standalone-versus-compact class-source granularity remains a separate bounded caveat.

- 2026-07-01 B010 UID0000O9 empty-emitter family implementation:
  - Before: `86/88`, generated `NexusTK/util/StdioFile.cpp` had 15 family emitters with one filled constructor and 14 remaining empty markers.
  - After: `88/90`; preserved `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"` and `CANONICAL_OWNER:FILE`.
  - Summary/evidence: incorporated the accepted family audit and route. The file root remains the concrete StdioFile owner, not FileIO/PathUtil/raw-vtable/deleting-destructor ownership. Exact method children now emit formal source or no-code comments through the existing class/aggregate route, with confidence capped by inferred original file granularity and public naming.
- 2026-06-29 B006 UID0001IQ constructor implementation:
  - Scores unchanged for this file.
  - Summary/evidence: constructor [UID:0001IQ][0x00582070-0x0058209a.StdioFileConstructor](by-memory/0x00582070-0x0058209a.StdioFileConstructor.md) is now source-ready at `90/93` and should emit into `NexusTK/util/StdioFile.cpp` through the existing [UID:0000E6][StdioFile](by-class/StdioFile.md) class route. MCP session `3fa0535f` reconfirmed exact range/bytes/padding, one-block/no-string/no-constant state, base-constructor callee, five construction callers, vtable refs, field provenance, and rejected no-code/manual-vtable/caller/FileIO/PathUtil alternatives. The standalone `StdioFile.cpp` versus compact `FileIO.cpp` caveat is preserved as nonblocking for this constructor.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `76` and confidence to `78`.
  - Evidence: document captures concrete file-stream role, proposed contents, vtable/layout refs, File/DAT/audio boundaries, and cross-references; completion remains lower because method behavior, callers, and reconstructed C++ shape are only summarized.
- 2026-05-31 reconstruction path and IDA recheck:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, scores were `76/78`, and the module path used `util/StdioFile.cpp` without an explicit generated root.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`, scores `78/82`, and proposed module `NexusTK/util/StdioFile.cpp`.
  - Summary/evidence: IDA MCP reconfirmed the main `StdioFile` island, `0x004f5ad0` vtable-only `GetSize`, `0x0062d5ac` concrete vtable slot map, and caller spread from startup/menu/map/audio paths. At that time C++ reconstruction remained blank because the per-method source rewrite and final split from `File.cpp` were not yet complete enough for final-source-quality code; the 2026-07-01 B010 callback supersedes that family-wide blank state.
- 2026-06-06 parent-chain evidence sync:
  - What existed before: this file was scored `78/82`, leaving the attached [UID:0000E6][StdioFile](by-class/StdioFile.md) class parent chain below the documented file-root gate.
  - Changed to: completion `82`, confidence `84`.
  - Summary/evidence: the constructor, executable island, virtual position/read cluster, line-read helpers, vtable, layout, and caller evidence now justify this as the active `NexusTK/util/` root for the `StdioFile` class while preserving the final `StdioFile.cpp` versus compact `FileIO.cpp` split caveat. No reconstruction C++ was added.
- 2026-06-12 A004 Batch 297 strict-gate refresh:
  - Before: `82/84`, enough for the old attachment note but below the current strict 85/85 gate.
  - After: `85/86`; added [UID:0003H2][StdioFileLayout](by-type/by-struct/StdioFileLayout.md) as the exact concrete layout child split from the mixed stream-layout index.
  - Summary/evidence: live IDA MCP reconfirmed method sizes, vtable refs, `Open` field writes, and caller evidence; final standalone `StdioFile.cpp` versus compact `FileIO.cpp` grouping remains below final-source certainty.
- 2026-06-12 A004 Batch 319 vtable split sync:
  - Scores remain `85/86`.
  - Added [UID:0003I1][StdioFileVtable](by-type/by-vtable/StdioFileVtable.md) as the exact source-local vtable child for the `StdioFile` class/source root; [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md) is now a non-emitting shared slot-layout index.
- 2026-06-16 A002 file-boundary refresh:
  - Before: `85/86`.
  - After: `86/88`.
  - Summary/evidence: live IDA MCP reconfirmed the complete StdioFile method-size map, non-contiguous `GetSize`, vtable anchor, constructor/open/read-all caller sets, and the PathUtil/DAT/audio exclusions. The remaining source-quality blocker is only original `StdioFile.cpp` versus compact `FileIO.cpp` granularity, not behavior, ownership, or reachability.
