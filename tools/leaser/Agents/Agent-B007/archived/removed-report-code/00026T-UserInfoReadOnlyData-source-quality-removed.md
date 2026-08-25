<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B007\00026T-UserInfoReadOnlyData-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00026T-UserInfoReadOnlyData-source-quality.md](00026T-UserInfoReadOnlyData-source-quality.md)
- Source report SHA256 before cleanup: `10457BB68879D5E23904CF311537F0FF32AD12F9E247F2868A369A42E814418A`
- Cleanup generated: `2026-08-11T12:47:12Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `343-351`
- Original language: `powershell`
- Block SHA256: `FB0EDC371B58B59B4917F4EEEAC796D2FEE2D39D70C5D25B668F724BC5EE8732`

```powershell
python source-3/project-documentation/tools/validator.py --queue-timeout 120 --mode file --file by-memory\0x0062e624-0x0062e8fc.UserInfoReadOnlyData.md --apply
python source-3/project-documentation/tools/validator.py --queue-timeout 120 --mode file --file by-file\UserInfoDialogPane.md --apply
python source-3/project-documentation/tools/validator.py --queue-timeout 120 --mode file --file by-class\UserInfoDialogPane.md --apply
python source-3/project-documentation/tools/validator.py --queue-timeout 120 --mode file --file by-memory\0x0062e8fc-0x0062eccc.UserListReadOnlyData.md --apply
python source-3/project-documentation/tools/validator.py --queue-timeout 120 --mode file --file by-memory\0x0062e8fc-0x0062e998.UserListDialogPaneVtableData.md --apply
python source-3/project-documentation/tools/validator.py --queue-timeout 120 --mode file --file by-class\UserListDialogPane.md --apply
python source-3/project-documentation/tools/validator.py --queue-timeout 120 --mode file --file by-file\UserListDialogPane.md --apply
```
