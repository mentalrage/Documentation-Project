<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B009\0002JG-StringMenuItemScalarDeletingDestructor-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002JG-StringMenuItemScalarDeletingDestructor-source-quality.md](0002JG-StringMenuItemScalarDeletingDestructor-source-quality.md)
- Source report SHA256 before cleanup: `6C31481091F95F7C60F5B876A9F7A273B0297E49CB85C8CE1AC57FD5BCDFAF91`
- Cleanup generated: `2026-08-11T12:47:14Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `429-436`
- Original language: `powershell`
- Block SHA256: `59A275EE739233C5E99925C1913CDE8DD6D44B64F0B0DE38BAF4D9E1F05159EC`

```powershell
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor.md --apply
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-class\StringMenuItem.md --apply
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-type\by-vtable\MenuItemVtables.md --apply
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0061eb94-0x0061ebf0.MenuItemVtableData.md --apply
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode autogen --apply
rg -n "0002JG|0x00517400|StringMenuItemScalarDeletingDestructor" E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md E:\NTK\GhidraBridge\source-3\project-documentation\auto-generated\-ag-memory-coverage.md E:\NTK\GhidraBridge\source-3\project-documentation\project-level\-auto-completion-stats.md
```
