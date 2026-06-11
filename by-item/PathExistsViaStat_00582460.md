*** UID:0000V6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PathExistsViaStat_00582460

## Status

- Confidence: strong
- Address range: [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md)
- Staged source owner: [UID:0000MI][PathUtil](by-file/PathUtil.md) under the [UID:0000JD][FileIO](by-file/FileIO.md) umbrella; final source may still fold into a compact `NexusTK/util/FileIO.cpp`
- Historical generated source candidate: `PathExistsViaStat_00582460.cpp`; use only as search context, not as authority.

## Function Role

`PathExistsViaStat` is a shared wide-path existence probe. It calls the imported `_wstat`-style function pointer in `dword_69BE18` against a stack-local stat buffer and returns `true` when the stat call succeeds.

`dword_69BE18` is the `_wstat64i32` entry in the process-wide [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md), initialized by [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md). Older generated output declared it locally, but final ownership should stay with [UID:0000ML][PlatformApi](by-file/PlatformApi.md).

## Caller Evidence

IDA caller checks on 2026-05-24 show this helper used from:

- startup-logo movie selection (`LOGO.PAK` / `LOGO.PAD`)
- `Application::Startup` when probing `NEXON.LGO`
- `MainMenuPane` resource loading for `LEVEL.BMP`
- `MapPane::LoadMapFromFile` for local `.cmp` map files
- the Miles AIL file-open callback before constructing a [UID:0000E6][StdioFile](by-class/StdioFile.md)

B001-022 rechecked the exact memory page on 2026-06-10 with live IDA MCP: the function is `0x00582460-0x00582495`, decompilation is a single `dword_69BE18(path, stackStatBuffer) != -1` boolean return, callers are `0x004f5765`, `0x004f5781`, `0x004f640d`, `0x004f6853`, `0x00504c7d`, and `0x0057b6be`, and callees are only the wide stat dispatch slot and the stack-cookie check.

## Ownership Notes

Treat this as utility file/path support. It is adjacent to `StdioFile` in memory and API role, but its caller spread is broader than one class. It is distinct from [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), which probes the DAT archive manager.

B001-022 also assigns [UID:00022K][0x004b81f0-0x004b821e.FileExists](by-memory/0x004b81f0-0x004b821e.FileExists.md) to the same [UID:0000MI][PathUtil](by-file/PathUtil.md) root. That open-based helper is not object-stateful and matches this stat-based helper's source role.

## Autogen Status

- Reconstructable: true; this is NexusTK-owned source helper code.
- Autogen parent: [UID:0000MI][PathUtil](by-file/PathUtil.md), which now stages `auto-generated/NexusTK/util/PathUtil.cpp`.
- C++ emission: none. The exact by-memory page is the canonical final-body owner, and final output should not use older generated bodies until the platform dispatch pointer is named through [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md) rather than emitted as a local `dword_69BE18`.

## Cross-References

- [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md)
- [UID:0000MI][PathUtil](by-file/PathUtil.md)
- [UID:0000JD][FileIO](by-file/FileIO.md)
- [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md)
- [UID:0000E6][StdioFile](by-class/StdioFile.md)
- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)

## Changes

- 2026-06-10 B001-022 strict-gate refresh:
  - Before: `COMPLETION:80`, `CONFIDENCE:86`, attached to PathUtil but below the current strict child-completion gate.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:88`.
  - Summary/evidence: live IDA MCP reconfirmed the exact function range, stat-buffer boolean body, six-call-site spread, dispatch-table dependency, and relationship to the newly assigned [UID:00022K][0x004b81f0-0x004b821e.FileExists](by-memory/0x004b81f0-0x004b821e.FileExists.md) sibling helper.
- 2026-06-03 parent attachment:
  - Before: the item was reconstructable but unassigned, and the proposed source owner only named the FileIO umbrella plus `PathUtil.cpp`/`StdioFile.cpp` alternatives.
  - Changed to: `COMPLETION:74`, `AUTOGEN_PARENT_UID:0000MI`, and staged owner [UID:0000MI][PathUtil](by-file/PathUtil.md), while leaving C++ blank.
  - Summary/evidence: [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md), [UID:0000JD][FileIO](by-file/FileIO.md), and [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) support the util placement; the exact final source split and platform dispatch declaration remain unresolved.
- 2026-06-06 evidence wording and score refresh:
  - Before: the item still cited a recovered source path and stayed at `74/85` even though exact range, dispatch dependency, caller spread, and parent attachment were already documented.
  - Changed to: completion `80`, confidence `86`, with generated-source naming demoted to search context only.
  - Summary/evidence: [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md) records the exact function range, stack stat-buffer behavior, dispatch-table xrefs, and caller list; [UID:0000MI][PathUtil](by-file/PathUtil.md) and [UID:0000JD][FileIO](by-file/FileIO.md) provide the staged utility owner. C++ remains blank because the final dispatch-pointer declaration and `PathUtil.cpp` versus `StdioFile.cpp` split are unresolved.
