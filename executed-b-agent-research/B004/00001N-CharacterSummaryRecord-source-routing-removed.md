<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B004\00001N-CharacterSummaryRecord-source-routing.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00001N-CharacterSummaryRecord-source-routing.md](00001N-CharacterSummaryRecord-source-routing.md)
- Source report SHA256 before cleanup: `B7317BD90BD5F98AAE0D4957EAD9CF7460D1B9E0D127EF5A1535682A6AB405CF`
- Cleanup generated: `2026-08-11T12:47:06Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `441-448`
- Original language: `powershell`
- Block SHA256: `64FB1DCB1EC3E9D3AE3AA4476770EC00F90C6C6AA33D7453EFBDCE5C919A036B`

```powershell
python .\tools\validator.py --mode file --file .\by-class\CharacterSummaryRecord.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\CharacterSummaryRecord.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-type\by-struct\UserStatusPaneSummaryFields.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\UserStatusPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\UserStatusPane.md --apply --queue-timeout 240
```
