<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0001NR-OldUserStatusPane-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001NR-OldUserStatusPane-source-quality.md](0001NR-OldUserStatusPane-source-quality.md)
- Source report SHA256 before cleanup: `9EEF202E9416C4281F5DE348855DB6994DF99A71632590997468CE5B1C259464`
- Cleanup generated: `2026-08-11T12:47:01Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `590-601`
- Original language: `powershell`
- Block SHA256: `22E0B7B0DECFF5C5A89100AE1E7F5D771C210B031CCE30A83B6475F3197EBD02`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x005bda40-0x005bfbc1.OldUserStatusPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005bf110-0x005bf14b.OldUserStatusPaneInvalidateStatusFieldRect.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005bf150-0x005bf3b0.OldUserStatusPaneStatusFieldRectLookup.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005bf3b0-0x005bf481.OldUserStatusPaneDrawNumberGlyphString.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005bf490-0x005bf51a.OldUserStatusPaneApplyLegacyPositionPacket.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005bf520-0x005bf670.OldUserStatusPaneApplyLegacyMovementStep.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005bf670-0x005bf7c0.OldUserStatusPaneApplyLegacyMovementStepAlt.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005bf7c0-0x005bfbc1.OldUserStatusPaneApplyLegacyStatusPayload.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\OldUserStatusPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\UserStatusPane.md --apply --queue-timeout 240
```
