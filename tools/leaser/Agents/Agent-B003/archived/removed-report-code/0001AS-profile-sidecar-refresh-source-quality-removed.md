<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0001AS-profile-sidecar-refresh-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001AS-profile-sidecar-refresh-source-quality.md](0001AS-profile-sidecar-refresh-source-quality.md)
- Source report SHA256 before cleanup: `FDDDA7BF95F977EB78A426A29EB6ED33C64853583CDE3B1C2995371592CA5E5A`
- Cleanup generated: `2026-08-11T12:47:04Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `371-379`
- Original language: `powershell`
- Block SHA256: `7AD6F0B0AC190ABA289C37742F0759BAEA986EA524F03897E7676D8586A8F362`

```powershell
Get-Content tools/leaser/Agents/Supervisor.md
Get-Content tools/leaser/Agents/Agent-B003/goal.md
Get-Content tools/leaser/Agents/Agent-B003/notes.md
rg -n "0001AS|ProfileSidecarRefresh|RefreshSelectedProfileData|0x005063e0|005063e0" source-3/project-documentation/tools/leaser/Agents -g "*.md"
rg -n "0x00575650|00575650|0x00575670|00575670|0x00575850|00575850|0x00574bb0|00574bb0" source-3/project-documentation -g "*.md"
Get-Item source-3/project-documentation/auto-generated/NexusTK/profile/ProfileStorage.cpp
rg -n "0001AS|00027P|0002AA" source-3/project-documentation/by-memory/-coverage-report.md
```
