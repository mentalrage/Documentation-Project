<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B007\000256-EmployeeDialogReadOnlyData-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000256-EmployeeDialogReadOnlyData-source-quality.md](000256-EmployeeDialogReadOnlyData-source-quality.md)
- Source report SHA256 before cleanup: `2F4FFC972EADBA0E2BD81B223283CDD2D9E2E994685B78A93968E06F12F9DA4A`
- Cleanup generated: `2026-08-11T12:47:12Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `296-302`
- Original language: `powershell`
- Block SHA256: `A14184D66E1AB15BC62D9D175C95262E4B0A71331DA56CE35C39C5B2643B5781`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00618efc-0x0061929c.EmployeeDialogReadOnlyData.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x0061916c-0x0061929c.EmployeeDialogResourceLiteralTail.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x00618efc-0x00618f98.EmployeeDialogPaneVtableData.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-type\by-vtable\EmployeeDialogPaneVtables.md --apply --queue-timeout 240 --wait-generated
```
