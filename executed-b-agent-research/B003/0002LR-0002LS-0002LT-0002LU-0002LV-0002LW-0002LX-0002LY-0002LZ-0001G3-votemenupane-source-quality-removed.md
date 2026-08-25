<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0002LR-0002LS-0002LT-0002LU-0002LV-0002LW-0002LX-0002LY-0002LZ-0001G3-votemenupane-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002LR-0002LS-0002LT-0002LU-0002LV-0002LW-0002LX-0002LY-0002LZ-0001G3-votemenupane-source-quality.md](0002LR-0002LS-0002LT-0002LU-0002LV-0002LW-0002LX-0002LY-0002LZ-0001G3-votemenupane-source-quality.md)
- Source report SHA256 before cleanup: `A5867E86582E20EDAEE099EA42A5A0B0B9AFD64CB137D315BFFB67152AC0A042`
- Cleanup generated: `2026-08-11T12:47:05Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `783-792`
- Original language: `powershell`
- Block SHA256: `03D26412E825B88677C7E39394C2FC82D3862D9419BBD18325BE5353E4CB765D`

```powershell
Get-Content tools\leaser\Agents\Supervisor.md
Get-Content tools\leaser\Agents\Agent-B003\goal.md
Get-Content tools\leaser\by-structure.md
Get-Content tools\leaser\inference_research.md
rg -n "0002LR|0002LS|0002LT|0002LU|0002LV|0002LW|0002LX|0002LY|0002LZ|0001G3|VoteMenuPane" source-3\project-documentation
Select-String -Path source-3\project-documentation\by-memory\-coverage-report.md -Pattern "0002LR|0002LS|0002LT|0002LU|0002LV|0002LW|0002LX|0002LY|0002LZ|0001G3"
rg -n "sub_5552A0|0x005552a0|sub_544690|0x00544690" source-3\project-documentation
Get-Content source-3\project-documentation\tools\leaser\Agents\Agent-B001\research\executed\0002LQ-votemenupane-raw-constructor-source-quality.md
```
