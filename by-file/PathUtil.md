*** UID:0000MI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# PathUtil

## Status

- Confidence: strong for helper behavior; medium for standalone original file.
- Proposed module: `util/PathUtil.cpp` or folded into [UID:0000O9][StdioFile](by-file/StdioFile.md).
- Umbrella doc: [UID:0000JD][FileIO](by-file/FileIO.md)
- Current recovered source: `source-3/simroot_v2/recovered/PathExistsViaStat_00582460.cpp`

## File Role

`PathUtil.cpp` is a placeholder for small wide-path filesystem helpers. The currently documented function is a shared `_wstat`-based existence probe used by startup, menu/art loading, map file loading, and audio file callback paths.

The `_wstat` callee is not a local PathUtil global. It is the `0x0069be18` entry in the process-wide [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md), initialized by [UID:0000ML][PlatformApi](by-file/PlatformApi.md) at [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md).

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:0000V6][PathExistsViaStat_00582460](by-item/PathExistsViaStat_00582460.md) | [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md) | Returns whether `_wstat` can see a wide path. |

## Boundary Notes

This should not be owned by startup, map, or audio merely because those systems call it. It also should not own `dword_69BE18`; that pointer belongs to the platform API dispatch table. If no more path helpers are found, folding the helper into `StdioFile.cpp` is likely more source-faithful than leaving a one-function source file.

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
