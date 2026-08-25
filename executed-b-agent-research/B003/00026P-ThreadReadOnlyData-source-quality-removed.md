<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\00026P-ThreadReadOnlyData-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00026P-ThreadReadOnlyData-source-quality.md](00026P-ThreadReadOnlyData-source-quality.md)
- Source report SHA256 before cleanup: `661180400899C148BC60776DD86BF678BC7E1F29B7489413FE4102924EB1A8AC`
- Cleanup generated: `2026-08-11T12:47:04Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `401-407`
- Original language: `powershell`
- Block SHA256: `9384E10349D66AAF06E0E6290E9B518B3BE673C2E3CB443C6CD34DB7AF8E4164`

```powershell
Select-String -Path 'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\*.md','E:\NTK\GhidraBridge\source-3\project-documentation\by-class\*.md','E:\NTK\GhidraBridge\source-3\project-documentation\by-file\*.md' -Pattern 'EL32\.DLL|0x0062e2d8|0x0062e338.ThreadReadOnlyData|0x0062e268-0x0062e338|off_62E2D0'

Select-String -Path 'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md' -Pattern '00026O|00026P|00026Q|0003E0|0x0062e268|0x0062e334|0x0062e338'

Select-String -Path 'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0062e268-0x0062e334.ThreadReadOnlyData.md' -Pattern 'KERNEL32\.DLL|EL32\.DLL|0x0062e334|TimerHandler'
```
