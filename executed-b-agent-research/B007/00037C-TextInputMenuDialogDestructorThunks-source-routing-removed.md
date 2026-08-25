<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B007\00037C-TextInputMenuDialogDestructorThunks-source-routing.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00037C-TextInputMenuDialogDestructorThunks-source-routing.md](00037C-TextInputMenuDialogDestructorThunks-source-routing.md)
- Source report SHA256 before cleanup: `810E8A891679C47EED8A4CC64CE6CE03A8C966CD415F624AD4AD8CE45DD5EDDC`
- Cleanup generated: `2026-08-11T12:47:12Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `305-310`
- Original language: `powershell`
- Block SHA256: `2E3C13E0A7C391968562B008164E2387CF87B8C54B304BF7626C4C1010C4B5AC`

```powershell
python .\source-3\project-documentation\tools\validator.py --mode file --file by-memory\0x00520b29-0x00520b3e.TextInputMenuDialogDestructorThunks.md --apply --queue-timeout 240
python .\source-3\project-documentation\tools\validator.py --mode file --file by-memory\0x00520d50-0x00520d98.TextInputMenuDialogScalarDeletingDestructor.md --apply --queue-timeout 240
python .\source-3\project-documentation\tools\validator.py --mode file --file by-class\TextInputMenuDialog.md --apply --queue-timeout 240
python .\source-3\project-documentation\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240
```
