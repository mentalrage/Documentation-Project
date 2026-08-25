<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B010\0000ER-TextInputMenuDialog-class-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000ER-TextInputMenuDialog-class-source-quality.md](0000ER-TextInputMenuDialog-class-source-quality.md)
- Source report SHA256 before cleanup: `A3D520CE661973F4201B7D8107AA7EB52161732845B152AEDD70446ECC9A9E7A`
- Cleanup generated: `2026-08-11T12:47:15Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `342-347`
- Original language: `powershell`
- Block SHA256: `29F796E42D7B16D97DFB5E58286418EDB7C5EA7E0A3942F7FB7B073C2C9B01AD`

```powershell
python .\tools\validator.py --mode file --file by-class/TextInputMenuDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/TextMenuDialogs.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `351-355`
- Original language: `powershell`
- Block SHA256: `49C4F87C597DF10085A97698C1DEDDF7F7B55363BFD825B697196A76150F07BA`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x00520b29-0x00520b3e.TextInputMenuDialogDestructorThunks.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x00520d50-0x00520d98.TextInputMenuDialogScalarDeletingDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md --apply --queue-timeout 240
```
