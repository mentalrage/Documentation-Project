<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0002LQ-votemenupane-raw-constructor-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002LQ-votemenupane-raw-constructor-source-quality.md](0002LQ-votemenupane-raw-constructor-source-quality.md)
- Source report SHA256 before cleanup: `AE1B3147370E60A71B976E24B1715B01A49AF82AEDAA22F8C3959EFC070E671C`
- Cleanup generated: `2026-08-11T12:46:58Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `199-207`
- Original language: `powershell`
- Block SHA256: `B23729E26D1C76B9E2D1DB80F38075E536600856171C4FA171A46DAC485F9B40`

```powershell
Get-Content E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\goal.md
Get-Content E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\notes.md
Get-Content E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Supervisor.md
Get-Content E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\by-structure.md
Get-Content E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\inference_research.md
rg -n "sub_544460|0x00544460|00544460|Pane constructor" E:\NTK\GhidraBridge\source-3\project-documentation
Select-String -Path E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md -Pattern "0002LQ|0069ba38-0x0069ba3c" -Context 1,1
```
