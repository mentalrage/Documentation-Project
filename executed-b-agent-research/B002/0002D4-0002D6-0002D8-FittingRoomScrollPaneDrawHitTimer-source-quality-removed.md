<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0002D4-0002D6-0002D8-FittingRoomScrollPaneDrawHitTimer-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002D4-0002D6-0002D8-FittingRoomScrollPaneDrawHitTimer-source-quality.md](0002D4-0002D6-0002D8-FittingRoomScrollPaneDrawHitTimer-source-quality.md)
- Source report SHA256 before cleanup: `D518A56EAAC274EF265518F8C87B49A9808C05A6D75C9EDBDFDB99D5B6FFA25A`
- Cleanup generated: `2026-08-11T12:47:01Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `711-718`
- Original language: `powershell`
- Block SHA256: `834C38874696966DEB4CC342D7AD7CDC3A7758D7E309190CD21FAF79C4F37FC9`

```powershell
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0041da70-0x0041daa3.FittingRoomScrollPaneOnTimer.md --apply
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0041dab0-0x0041e1c6.FittingRoomScrollPaneOnDraw.md --apply
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0041e1d0-0x0041e4ed.FittingRoomScrollPaneHitTestPart.md --apply
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md --apply
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode autogen --apply --queue-timeout 240
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode rescore --apply --queue-timeout 240
```
