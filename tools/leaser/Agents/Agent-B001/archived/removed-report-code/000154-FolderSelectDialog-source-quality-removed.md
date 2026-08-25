<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\000154-FolderSelectDialog-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000154-FolderSelectDialog-source-quality.md](000154-FolderSelectDialog-source-quality.md)
- Source report SHA256 before cleanup: `1B7EE523B9F0336E129BEB481956AE7A1B4BEBD181346062AD448CA86E53ABD4`
- Cleanup generated: `2026-08-11T12:46:56Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `232-245`
- Original language: `powershell`
- Block SHA256: `243021243156DC8AC5BFE291C9980CB923A74AB45D7AB4518618B6B72F541E10`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004b1590-0x004b1b87.FolderSelectDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004b1590-0x004b18d6.FolderSelectDialogConstructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004b18d6-0x004b1920.FolderSelectDialogConstructorCleanupAndPadding.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004b1920-0x004b1a00.FolderSelectDialogOnCommand.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004b1b05-0x004b1b20.FolderSelectDialogAdjustorThunksAndPadding.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004b1b20-0x004b1b87.FolderSelectDialogScalarDeletingDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\FolderSelectDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\FolderSelectDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md --apply --queue-timeout 240
```
