<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\00045A-FolderSelectDialogPopulateDriveList-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00045A-FolderSelectDialogPopulateDriveList-source-quality.md](00045A-FolderSelectDialogPopulateDriveList-source-quality.md)
- Source report SHA256 before cleanup: `E27A870869DF0D18007318A30828D315DDD4A50E3AD847DCEDEF4A1388BBF8B8`
- Cleanup generated: `2026-08-11T12:47:10Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `596-605`
- Original language: `powershell`
- Block SHA256: `A6002B82AFC9917197C5783FB35CC6799E7BF219FEF5FD4AE1DA77D0091495C4`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004b1920-0x004b1a00.FolderSelectDialogOnCommand.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/FolderSelectDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/FolderSelectDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004b1590-0x004b18d6.FolderSelectDialogConstructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList.md --apply --wait-generated --queue-timeout 900
```
