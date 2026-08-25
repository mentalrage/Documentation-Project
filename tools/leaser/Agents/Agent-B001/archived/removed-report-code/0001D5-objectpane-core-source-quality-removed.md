<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0001D5-objectpane-core-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001D5-objectpane-core-source-quality.md](0001D5-objectpane-core-source-quality.md)
- Source report SHA256 before cleanup: `D3874007D8164ADC0E0885D90ADE3C0E9C29DC489D04A1C75FE1762145CB00B5`
- Cleanup generated: `2026-08-11T12:46:57Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `199-208`
- Original language: `powershell`
- Block SHA256: `3EF85AFC33B87D373ED12E04B639C037B8EE3B35BBAA08EFDC8F89EB74DA19C0`

```powershell
Get-Content -Raw "E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\goal.md"
Get-Content -Raw "E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\notes.md"
Get-Content -Raw "E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Supervisor.md"
Get-Content -Raw "E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005372d0-0x005378fa.ObjectPane.md"
Get-Content -Raw "E:\NTK\GhidraBridge\source-3\project-documentation\by-class\ObjectPane.md"
Get-Content -Raw "E:\NTK\GhidraBridge\source-3\project-documentation\by-file\ObjectPane.md"
Select-String -Path "E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md" -Pattern "0001D5|005372d0|ObjectPaneClearOutputRects|ObjectPaneGetEmptyRect" -Context 2,3
python "E:\NTK\GhidraBridge\source-3\project-documentation\tools\int_convert.py" 0xf8
```
