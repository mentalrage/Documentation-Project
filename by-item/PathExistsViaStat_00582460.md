*** UID:0000V6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PathExistsViaStat_00582460

## Status

- Confidence: strong
- Address range: [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md)
- Proposed source owner: [UID:0000JD][FileIO](by-file/FileIO.md), likely `util/PathUtil.cpp` or `util/StdioFile.cpp`
- Current generated file: `source-3/simroot_v2/recovered/PathExistsViaStat_00582460.cpp`

## Function Role

`PathExistsViaStat` is a shared wide-path existence probe. It calls the imported `_wstat`-style function pointer in `dword_69BE18` against a stack-local stat buffer and returns `true` when the stat call succeeds.

`dword_69BE18` is the `_wstat64i32` entry in the process-wide [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md), initialized by [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md). The generated helper file currently declares it locally, but final ownership should stay with [UID:0000ML][PlatformApi](by-file/PlatformApi.md).

## Caller Evidence

IDA caller checks on 2026-05-24 show this helper used from:

- startup-logo movie selection (`LOGO.PAK` / `LOGO.PAD`)
- `Application::Startup` when probing `NEXON.LGO`
- `MainMenuPane` resource loading for `LEVEL.BMP`
- `MapPane::LoadMapFromFile` for local `.cmp` map files
- the Miles AIL file-open callback before constructing a [UID:0000E6][StdioFile](by-class/StdioFile.md)

## Ownership Notes

Treat this as utility file/path support. It is adjacent to `StdioFile` in memory and API role, but its caller spread is broader than one class. It is distinct from [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), which probes the DAT archive manager.

## Cross-References

- [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md)
- [UID:0000JD][FileIO](by-file/FileIO.md)
- [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md)
- [UID:0000E6][StdioFile](by-class/StdioFile.md)
- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
