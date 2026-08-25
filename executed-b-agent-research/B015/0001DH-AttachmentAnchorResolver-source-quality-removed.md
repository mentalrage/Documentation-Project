<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B015\0001DH-AttachmentAnchorResolver-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001DH-AttachmentAnchorResolver-source-quality.md](0001DH-AttachmentAnchorResolver-source-quality.md)
- Source report SHA256 before cleanup: `10DE1B855B3201829CBECEDEC805FF24AE4AFB0A663155A6C9BE3C8C1CF3D57A`
- Cleanup generated: `2026-08-11T12:47:18Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `417-425`
- Original language: `powershell`
- Block SHA256: `11971BDC10E2C6FEB118A0DAEF32D5DFFC1A83D32A97429F0D506BBE6366CFDD`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x0053c700-0x0053c92e.AttachmentAnchorResolver.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-class\AttachmentAnchorResolver.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-file\AttachmentAnchorResolver.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-file\AttachedObjectPane.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\-coverage-report.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode autogen --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode rescore --apply --queue-timeout 240 --lock-timeout -1
```

## Removed Block R002

- Original source lines: `429-433`
- Original language: `powershell`
- Block SHA256: `859AC925346AB61D28A4551D732658BCB46780D41350CCB6EF321C35ADCC2D8D`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x005374f0-0x005375e1.ObjectPaneAttachObject.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x005375f0-0x005376b5.ObjectPaneDetachObject.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x00537800-0x0053787a.ObjectPaneSetObjectData.md --apply --queue-timeout 240 --lock-timeout -1
```
