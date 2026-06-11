*** UID:0000MI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# PathUtil

## Status

- Confidence: strong for the paired helper behavior, `NexusTK/util/` placement, and caller-spread ownership; medium-high for whether the original source kept a standalone `PathUtil.cpp` instead of folding the helpers into a compact [UID:0000JD][FileIO](by-file/FileIO.md) translation unit.
- Proposed module: `NexusTK/util/PathUtil.cpp`, with a documented fallback to a compact `NexusTK/util/FileIO.cpp` only if later source-structure evidence proves the original project did not keep a standalone path helper file.
- Umbrella doc: [UID:0000JD][FileIO](by-file/FileIO.md)
- Historical generated source candidate: `PathExistsViaStat_00582460.cpp`; use only as search context, not as authority.
- Autogen root: `auto-generated/NexusTK/util/PathUtil.cpp`

## File Role

`PathUtil.cpp` is the active source root for small wide-path filesystem helpers. It now owns both observed source-authored existence probes: a `_wstat64i32`-based check used by startup/menu/map/audio paths and a `_wfopen`/`fclose` check used by DAT index and monster archive loading. The two helpers have different backing CRT APIs but the same direct source role: they answer whether a wide path can be opened or observed, without owning stream object state, archive state, render state, or the platform dispatch table.

The `_wstat` callee is not a local PathUtil global. It is the `0x0069be18` entry in the process-wide [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md), initialized by [UID:0000ML][PlatformApi](by-file/PlatformApi.md) at [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md).

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:0000V6][PathExistsViaStat_00582460](by-item/PathExistsViaStat_00582460.md) | [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md) | Returns whether `_wstat64i32` can see a wide path. The exact memory page is attached to this file root for autogen tracking; C++ remains blank under the final-code gate. |
| [UID:00022K][0x004b81f0-0x004b821e.FileExists](by-memory/0x004b81f0-0x004b821e.FileExists.md) | `0x004b81f0-0x004b821e` | Opens a wide path via the `_wfopen` dispatch slot in read-binary mode, closes the stream on success, and returns a boolean. B001-022 assigns it to this file root as the open-based sibling to `PathExistsViaStat`. |

## Boundary Notes

This should not be owned by startup, map, audio, DAT, or monster-image code merely because those systems call it. It also should not own `dword_69BE18` or `dword_69BE14`; those pointers belong to the platform API dispatch table. `StdioFile` is also weaker as a direct owner because its methods operate on object state and throw `FileError`, while these helpers are free boolean path probes.

`PathUtil.cpp` is a valid staged source root because [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) already lists it under `util/`, and the [UID:0000JD][FileIO](by-file/FileIO.md) umbrella separates the broad caller helpers from caller-owned startup, menu, map, archive, monster-image, and audio modules. The remaining file-granularity caveat is original-source layout only: a future source-tree pass may fold this root into compact `FileIO.cpp`, but the direct semantic owner remains the path utility layer.

## Score Rationale

- Completion is `87` because the page now records a valid generated root, exact `_wstat` and `_wfopen` helper ownership, caller-spread rationale, platform dispatch boundary, FileIO umbrella relationship, project-structure tie-in, and the B001-022 direct-parent decision.
- Confidence is `88` because the helper ranges, dispatch-table dependencies, and cross-subsystem caller sets are IDA-backed, and the sibling helper comparison rejects the narrower StdioFile/File/PlatformApi/DAT/monster alternatives. Confidence stays below final-audit quality because original source-file granularity and final source-facing helper names are still inferred.

## Cross-References

- [UID:0000JD][FileIO](by-file/FileIO.md)
- [UID:0000V6][PathExistsViaStat_00582460](by-item/PathExistsViaStat_00582460.md)
- [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md)
- [UID:00022K][0x004b81f0-0x004b821e.FileExists](by-memory/0x004b81f0-0x004b821e.FileExists.md)
- [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md)
- [UID:0000O9][StdioFile](by-file/StdioFile.md)

## Changes

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
