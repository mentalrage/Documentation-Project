<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\000211-webboard-oldmode-raw-rect-source-route.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000211-webboard-oldmode-raw-rect-source-route.md](000211-webboard-oldmode-raw-rect-source-route.md)
- Source report SHA256 before cleanup: `83EDDDF450D000374141286B41259E938327350D562FE59BEA83003A2E0EC170`
- Cleanup generated: `2026-08-11T12:46:58Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `377-386`
- Original language: `powershell`
- Block SHA256: `B4976BD6067226FECE65BBEF5DB3FF0F8E4B02A9C99EB3B2C4D6B753B2F92161`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python .\tools\validator.py --mode file --file by-memory\0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-class\WebBoardDialogOld.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-file\WebBoardDialog.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1
python .\tools\memory_ranges.py report
python .\tools\validator.py --mode rescore --apply --lock-timeout -1
```
