*** UID:0000MI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# PathUtil

## Status

- Confidence: strong for helper behavior and `NexusTK/util/` placement; medium for whether the original source kept a standalone `PathUtil.cpp` instead of folding the helper into [UID:0000O9][StdioFile](by-file/StdioFile.md).
- Proposed module: `NexusTK/util/PathUtil.cpp`, with a documented fallback to `NexusTK/util/StdioFile.cpp` if later source-structure evidence favors a compact file-I/O module.
- Umbrella doc: [UID:0000JD][FileIO](by-file/FileIO.md)
- Current recovered source: `source-3/simroot_v2/recovered/PathExistsViaStat_00582460.cpp`
- Autogen root: `auto-generated/NexusTK/util/PathUtil.cpp`

## File Role

`PathUtil.cpp` is a placeholder for small wide-path filesystem helpers. The currently documented function is a shared `_wstat`-based existence probe used by startup, menu/art loading, map file loading, and audio file callback paths.

The `_wstat` callee is not a local PathUtil global. It is the `0x0069be18` entry in the process-wide [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md), initialized by [UID:0000ML][PlatformApi](by-file/PlatformApi.md) at [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md).

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:0000V6][PathExistsViaStat_00582460](by-item/PathExistsViaStat_00582460.md) | [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md) | Returns whether `_wstat64i32` can see a wide path. The exact memory page is attached to this file root for autogen tracking; C++ remains blank. |

## Boundary Notes

This should not be owned by startup, map, or audio merely because those systems call it. It also should not own `dword_69BE18`; that pointer belongs to the platform API dispatch table. If no more path helpers are found, folding the helper into `StdioFile.cpp` is likely more source-faithful than leaving a one-function source file.

`PathUtil.cpp` is nevertheless a valid staged source root because [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) already lists it under `util/`, and the [UID:0000JD][FileIO](by-file/FileIO.md) umbrella separates the broad caller helper from caller-owned startup, menu, map, and audio modules. Treat the staged file as a conservative reconstruction handle, not final proof that the original tree had a one-helper file.

## Score Rationale

- Completion is raised to `78` because the page now records a valid generated root, exact helper/memory ownership, caller-spread rationale, platform dispatch boundary, and project-structure tie-in.
- Confidence is raised to `80` because existing IDA-backed pages agree on the helper range, `_wstat64i32` dispatch-table dependency, and cross-subsystem callers, while the project-structure map already places this candidate under `NexusTK/util/`.
- Confidence stays at the attachment threshold because fresh IDA MCP was unavailable on 2026-06-03, `wave3.py search symbol PathExistsViaStat` timed out, and the standalone-vs-`StdioFile.cpp` source split remains unresolved.

## Cross-References

- [UID:0000JD][FileIO](by-file/FileIO.md)
- [UID:0000V6][PathExistsViaStat_00582460](by-item/PathExistsViaStat_00582460.md)
- [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md)
- [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md)
- [UID:0000O9][StdioFile](by-file/StdioFile.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `72`, confidence `74`.
- Summary/evidence: the page documents the current helper, `_wstat` dispatch-table dependency, ownership boundary, and cross-references; completion remains modest because it is a one-helper placeholder and standalone source-file status is unresolved.
- 2026-06-03 path and attachment pass:
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the page scored `72/74`, leaving the by-file root in autogen error state.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"` and score `78/80`.
  - Summary/evidence: [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md), [UID:0000V6][PathExistsViaStat_00582460](by-item/PathExistsViaStat_00582460.md), [UID:0000JD][FileIO](by-file/FileIO.md), and [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) support a `NexusTK/util/` staging root. Final C++ remains blank because the generated body still treats `dword_69BE18` as local and the final `PathUtil.cpp` versus `StdioFile.cpp` split is not closed.
