<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0001BX-MenuDialogDestructorThunks-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001BX-MenuDialogDestructorThunks-source-quality.md](0001BX-MenuDialogDestructorThunks-source-quality.md)
- Source report SHA256 before cleanup: `9B88B1188AF43244B946B34633706D77DB49DDB7502DEA4BFCBF07B8081C11D9`
- Cleanup generated: `2026-08-11T12:47:01Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `292-296`
- Original language: `powershell`
- Block SHA256: `71305B29B95E220301D6D96F26FC259AB8C413A8C9EFE4BD3774D96131192A45`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor.md --apply --queue-timeout 240
```
