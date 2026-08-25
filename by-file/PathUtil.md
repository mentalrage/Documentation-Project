*** UID:0000MI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# PathUtil

## Status

- Confidence: very strong for the complete two-helper inventory, both exact behaviors and ranges, `NexusTK/util/PathUtil.cpp` canonical placement, required `PathUtil.h`, deterministic source order, caller-spread ownership, PlatformApi dependency boundary, and one-body duplicate routing; original lexical/header spelling remains inferred.
- Canonical module: `NexusTK/util/PathUtil.cpp`.
- Inferred declaration header: `NexusTK/util/PathUtil.h`, required because UID0001IZ callers span startup-logo, application, main-menu, map, and audio translation units.
- Umbrella doc: [UID:0000JD][FileIO](by-file/FileIO.md)
- Historical generated source candidate: `PathExistsViaStat_00582460.cpp`; use only as search context, not as authority.
- Autogen root: `auto-generated/NexusTK/util/PathUtil.cpp`
- Historical compact `FileIO.cpp` / `StdioFile.cpp` folding remains documented below as a superseded layout theory, not a current source-placement blocker.
- Complete source disposition: [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md) emits the include preamble, position-10 stat helper, and complete two-declaration header; [UID:00022K][0x004b81f0-0x004b821e.FileExists](by-memory/0x004b81f0-0x004b821e.FileExists.md) emits only the position-20 open helper. [UID:0000V6][PathExistsViaStat_00582460](by-item/PathExistsViaStat_00582460.md) remains a non-emitting mirror.

## File Role

`PathUtil.cpp` is the active source root for small wide-path filesystem helpers. It now owns both observed source-authored existence probes: a `_wstat64i32`-based check used by startup/menu/map/audio paths and a `_wfopen`/`fclose` check used by DAT index and monster archive loading. The two helpers have different backing CRT APIs but the same direct source role: they answer whether a wide path can be opened or observed, without owning stream object state, archive state, render state, or the platform dispatch table.

The `_wstat` callee is not a local PathUtil global. It is `g_pfnWideStat`, the `0x0069be18` entry in the process-wide [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md), initialized by [UID:0000ML][PlatformApi](by-file/PlatformApi.md) at [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) and source-declared by [UID:0002AS][0x0069be14-0x0069bec4.WideApiDispatchPointerTable](by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md). The exact pointer type is `int (__cdecl *)(const wchar_t *, struct _stat64i32 *)`.

UID0001IZ supplies the source preamble, first body, and complete header. UID00022K supplies the second body. Their source order is fixed at positions 10 and 20 so the preamble/header-owning child always precedes its sibling:

The formal source preserves the exact 48-byte local and binary non-`-1` predicate for `PathExistsViaStat`, and the exact `L"rb"` open, null failure, `fclose`-on-success, and boolean result for `FileExists`. The compiler-generated /GS cookie remains implicit rather than appearing as handwritten source.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md) | Exact 53-byte function, SHA256 `9283C746FB482BB7DED5096C9BA3E63F003646AACC801D31BA549C69D260CAA0`; seven leading and eleven trailing `0xcc` bytes | Position-10 emitter for the include preamble and `_wstat64i32` path probe; exact cdecl ABI, 48-byte `_stat64i32` local, exact `!= -1` predicate, six callers, complete CPP, and complete `PathUtil.h` declarations. |
| [UID:0000V6][PathExistsViaStat_00582460](by-item/PathExistsViaStat_00582460.md) | Same canonical UID0001IZ function | Non-reconstructable, non-emitting evidence/index mirror owned by UID0001IZ; blank emitter/formal prevents duplicate output. |
| [UID:00022K][0x004b81f0-0x004b821e.FileExists](by-memory/0x004b81f0-0x004b821e.FileExists.md) | Exact 46-byte function, SHA256 `B32A87D899AFDE2072FA2DAD67278AAC78EFB4FF54602EBC1FD554EB5A5CF27D`; five leading and two trailing `0xcc` bytes | Position-20 emitter for the `_wfopen` sibling. It calls `g_pfnWideOpenFile(path, L"rb")`, returns false on null, closes a successful stream, and returns true; exact callers are DAT-index direct/fallback probes and the monster-archive loop. |

## Complete Whole-File Inventory And Source Order

- The complete PathUtil-owned source inventory is exactly two free functions: `PathExistsViaStat` and `FileExists`. No additional PathUtil-owned function, helper, global, static, table, class, vtable, RTTI record, resource, import definition, initializer, destructor, exception helper, or compiler-authored body was found.
- Position 10 is UID0001IZ. Its CPP starts with `#include "PathUtil.h"` and `#include "../platform/PlatformApi.h"`, then defines `PathExistsViaStat`. Its H block owns `#pragma once` plus declarations for both helpers.
- Position 20 is UID00022K. Its CPP defines `FileExists`; its H block remains blank because UID0001IZ provides the single complete header route.
- UID0000V6 is the same canonical UID0001IZ entity represented as an evidence/index page. It remains `RECONSTRUCTABLE:FALSE`, owner UID0001IZ, with no emitter and blank formal CPP/H so the function is emitted exactly once.
- The pooled `L"rb"` literal, `_fclose`, `_stat64i32`, `g_pfnWideOpenFile`, and `g_pfnWideStat` are dependencies rather than PathUtil-owned definitions. The /GS cookie sequence in UID0001IZ is compiler-covered by the typed stack buffer.
- Neighboring [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md), [UID:00015U][0x004b8220-0x004b8284.BuildFieldMapPath](by-memory/0x004b8220-0x004b8284.BuildFieldMapPath.md), StdioFile methods, and the StdioFile scalar deleting wrapper are excluded by behavior, state, callers, and ownership rather than by adjacency alone.

## Source Header And Dependency Contract

- `PathUtil.cpp` owns the two free helper definitions and includes `PathUtil.h` plus `../platform/PlatformApi.h` rather than defining raw dispatch storage.
- `PathUtil.h` is required by nine calls in seven caller functions spread across DAT, monster-image, startup-logo, application, main-menu, map, and audio translation units. It contains exactly `bool PathExistsViaStat(const wchar_t *path);` and `bool FileExists(const wchar_t *path);` beneath `#pragma once`.
- `_stat64i32` is the exact 48-byte CRT structure required by UID0001IZ. Its current live layout includes `st_size` at `+0x14` and three 64-bit time fields at `+0x18/+0x20/+0x28`.
- `g_pfnWideStat` remains defined/initialized under PlatformApi. PathUtil consumes it with the exact `_wstat64i32` pointer type.
- `g_pfnWideOpenFile` / `_wfopen` remains the separate dependency used by UID00022K. Neither dispatch slot is PathUtil-owned storage.
- Source-facing helper/local names are descriptive human reconstructions. Raw `sub_*`, `dword_*`, `unk_*`, byte-array locals, and decompiler argument names are rejected from final source.

## Boundary Notes

This should not be owned by startup, map, audio, DAT, or monster-image code merely because those systems call it. It also should not own `dword_69BE18` or `dword_69BE14`; those pointers belong to the platform API dispatch table. `StdioFile` is also weaker as a direct owner because its methods operate on object state and throw `FileError`, while these helpers are free boolean path probes.

`PathUtil.cpp` is the canonical source root because [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) lists separate `File.cpp`, `StdioFile.cpp`, and `PathUtil.cpp` files, and [UID:0000JD][FileIO](by-file/FileIO.md) is explicitly a reviewed non-emitting umbrella. The compact `FileIO.cpp`/`StdioFile.cpp` folding theory is preserved as historical source-layout uncertainty, but current source ownership and generator roots reject it as the canonical reconstruction route.

The exact UID0001IZ range is physically adjacent to StdioFile code but reads no `this`, fields, vtable, stream handle, cached size, or object exception state. PlatformApi owns dispatch storage, while startup/menu/map/audio and DAT/monster modules are callers. Those relationships are dependencies and consumers, not direct ownership.

## Duplicate And Generated Output Policy

- UID0001IZ and UID00022K are the two source-bearing bodies under this root, in positions 10 and 20 respectively.
- UID0000V6 is an evidence mirror with `RECONSTRUCTABLE:FALSE`, owner UID0001IZ, blank emitters, and blank formal C++.
- UID00022K remains a separate source function with a blank H block because the shared header is emitted once by UID0001IZ.
- Generated `auto-generated/NexusTK/util/PathUtil.cpp` must contain the two includes followed by exactly the UID0001IZ and UID00022K definitions in positions 10/20. `PathUtil.h` must contain `#pragma once` and exactly the two declarations. Neither output may contain a PathUtil-specific empty-emitter marker, stub, placeholder, duplicate mirror, or compiler-glue body.
- Dated validator command `000000025126` produced the historical pre-callback state of one UID0001IZ body, one UID00022K empty marker, and no `PathUtil.h`. That snapshot documents the resolved defect and has no continuing current-state authority after later validation.
- Generated output is validator-owned and must never be hand-edited.

## Score Rationale

- Completion is `95` because the page records the exhaustive two-function inventory, both exact ranges/bytes/hashes/boundaries/ABIs/behaviors, all nine call sites in seven callers, complete dependency ownership, deterministic positions, exact CPP/H channels, duplicate and compiler-covered dispositions, generated closure contract, source placement, and rejected ownership alternatives.
- Confidence is `95` because live IDA and current target/support docs establish exact behavior, caller sets, dispatch types, owner/emitter routes, header need, and source order. Original lexical/header/include spelling and rebuilt compiler equivalence remain inferred, which prevents a score above 95 but does not leave a source-quality blocker.

## Cross-References

- [UID:0000JD][FileIO](by-file/FileIO.md)
- [UID:0000V6][PathExistsViaStat_00582460](by-item/PathExistsViaStat_00582460.md)
- [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md)
- [UID:00022K][0x004b81f0-0x004b821e.FileExists](by-memory/0x004b81f0-0x004b821e.FileExists.md)
- [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md)
- [UID:0002AS][0x0069be14-0x0069bec4.WideApiDispatchPointerTable](by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md)
- [UID:0000ML][PlatformApi](by-file/PlatformApi.md)
- [UID:0000O9][StdioFile](by-file/StdioFile.md)

## Changes

- 2026-08-16 B006 UID0000MI whole-file empty-emitter callback:
  - Raised `90/92` to `95/95` while preserving `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"` and file-root ownership.
  - Reconciled the whole-file inventory as exactly two source-authored free helpers and no owned data/class/compiler body; fixed deterministic UID0001IZ/UID00022K positions 10/20 and the one-header/one-mirror route.
  - Added FileExists exact 46-byte/hash/boundary/behavior/caller evidence, preserved PathExistsViaStat exact 53-byte/stat/predicate/caller evidence, and documented why the predicates coexist rather than duplicate one another.
  - Closed the source dependency through `PathUtil.h` and the shared PlatformApi declarations, preserved all rejected ownership and historical compact-folding evidence, and historicalized command 25126's one-body/one-empty/no-H output as the resolved pre-callback defect.

- 2026-07-24 B001 UID0001IZ source-root callback:
  - Raised `87/88` to `90/92` while preserving `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"` and file-root ownership.
  - Made `PathUtil.cpp` the canonical current source unit, inferred `PathUtil.h` for cross-module declarations, documented the `_stat64i32` and PlatformApi dispatch dependencies, and incorporated UID0001IZ's exact body/bytes/hash/ABI/predicate/caller/source evidence at file-root level.
  - Resolved duplicate output by routing UID0000V6 as a non-reconstructable mirror owned by UID0001IZ. UID0001IZ is now the sole source body; UID00022K remains a separate sibling outside the target report's coverage.
  - Preserved compact FileIO/StdioFile folding as a historical rejected/superseded layout theory rather than deleting it. Current FileIO and proposed-source-tree decisions mean it no longer blocks source placement or C++.
  - Added generated readback expectations and preserved PlatformApi, StdioFile, caller-module, DAT, and monster-image exclusions.

- 2026-06-10 B001-022 FileExists parent-gate repair:
  - Before: `COMPLETION:84`, `CONFIDENCE:86`, with [UID:00022K][0x004b81f0-0x004b821e.FileExists](by-memory/0x004b81f0-0x004b821e.FileExists.md) listed only as an unassigned candidate.
  - Changed to: `COMPLETION:87`, `CONFIDENCE:88`, and `FileExists` documented as an attached open-based path-existence helper.
  - Summary/evidence: live IDA MCP reconfirmed `FileExists` as a single free boolean helper with exact three-call-site spread, `_wfopen` dispatch read, and `_fclose` success path. Comparing it to [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md) and [UID:0001IT][0x005820d0-0x005821c9.StdioFileOpen](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md) makes this file the best direct parent under the strict 85/85 gate.
- 2026-06-08 A006 Batch 118 parent/source candidate update:
  - Before: `COMPLETION:82`, `CONFIDENCE:84`.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:86`.
  - Summary/evidence: added [UID:00022K][0x004b81f0-0x004b821e.FileExists](by-memory/0x004b81f0-0x004b821e.FileExists.md) as a candidate wide-path existence helper and documented its `_wfopen` dispatch dependency, archive/monster caller spread, and non-ownership by PlatformApi/DAT/monster modules. The score remains below `85` completion because direct source ownership is still unresolved against compact FileIO/StdioFile placement.
- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `72`, confidence `74`.
- Summary/evidence: the page documents the current helper, `_wstat` dispatch-table dependency, ownership boundary, and cross-references; completion remains modest because it is a one-helper placeholder and standalone source-file status is unresolved.
- 2026-06-03 path and attachment pass:
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the page scored `72/74`, leaving the by-file root in autogen error state.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"` and score `78/80`.
  - Summary/evidence: [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md), [UID:0000V6][PathExistsViaStat_00582460](by-item/PathExistsViaStat_00582460.md), [UID:0000JD][FileIO](by-file/FileIO.md), and [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) support a `NexusTK/util/` staging root. Final C++ remains blank because older generated output treated `dword_69BE18` as local and the final `PathUtil.cpp` versus `StdioFile.cpp` split is not closed.
- 2026-06-06 evidence wording and score refresh:
  - Before: the page still cited a recovered source path and kept the score at `78/80` despite the helper, item, memory range, dispatch-table boundary, caller spread, and project-tree placement now being documented consistently.
  - Changed to: completion `82`, confidence `84`, and generated-source names demoted to search context only.
  - Summary/evidence: [UID:0000V6][PathExistsViaStat_00582460](by-item/PathExistsViaStat_00582460.md), [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md), [UID:0000JD][FileIO](by-file/FileIO.md), [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md), and [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) support the stronger utility-root score. Final C++ remains blank under the `95/95` gate because dispatch declaration ownership and exact source split are still open.
