<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0002S6-change-spell-slot-raw-sender-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002S6-change-spell-slot-raw-sender-source-quality.md](0002S6-change-spell-slot-raw-sender-source-quality.md)
- Source report SHA256 before cleanup: `AB78B6DFE4C255E239178A1E9C6EAF9CA9E4DDD159699C04D4AD1B2112ABF8FF`
- Cleanup generated: `2026-08-11T12:47:05Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `363-371`
- Original language: `powershell`
- Block SHA256: `97F8223CD1EDB3DC8A88A720337208D5E823E0154701BFBC79BD54422397B090`

```powershell
Get-Content -Raw source-3/project-documentation/by-memory/0x005b3410-0x005b3485.ChangeSpellSlotPacketRawSender.md
Get-Content -Raw source-3/project-documentation/by-memory/0x005b32d0-0x005b340e.ChangeSpellSlotInputPaneSubmitSlotChange.md
Get-Content -Raw source-3/project-documentation/by-class/ChangeSpellSlotInputPane.md
Get-Content -Raw source-3/project-documentation/by-file/SpellInputPanes.md
Select-String -Path source-3/project-documentation/by-memory/-coverage-report.md -Pattern "0002S6|005b3410|005b3485|005b3490" -Context 3,3
Select-String -Path source-3/project-documentation/by-memory/-ignored.md -Pattern "005b3483|005b3485|ChangeSpellSlot" -Context 2,2
rg -n "0002S6|ChangeSpellSlotPacketRawSender|0x005b3410|005b31a0" source-3/project-documentation/tools/leaser/Agents/*/research source-3/project-documentation/tools/leaser/Agents/*/research/executed
```
