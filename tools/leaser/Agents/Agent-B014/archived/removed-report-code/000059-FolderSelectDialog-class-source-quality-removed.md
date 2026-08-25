<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B014\000059-FolderSelectDialog-class-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000059-FolderSelectDialog-class-source-quality.md](000059-FolderSelectDialog-class-source-quality.md)
- Source report SHA256 before cleanup: `FE0B7427A7773ED815D6A934906545B549840437DE130FB5BDBAC066E6FA99C2`
- Cleanup generated: `2026-08-11T12:47:18Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `540-543`
- Original language: `powershell`
- Block SHA256: `3182378345F7EC57566C86C29D02FD63C4A8A6FD9DC8D84CDDF7EC888BC2DF2B`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python .\tools\validator.py --mode file --file by-class\FolderSelectDialog.md --queue-timeout 240
```

## Removed Block R002

- Original source lines: `559-566`
- Original language: `powershell`
- Block SHA256: `3EBD22DE80B3563EC814CDBCD0F7D41163ACB667EB135CC49E228161BF24315A`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python .\tools\validator.py --mode file --file by-class\FolderSelectDialog.md --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\FolderSelectDialog.md --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004b1590-0x004b1b87.FolderSelectDialog.md --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md --queue-timeout 240
```
