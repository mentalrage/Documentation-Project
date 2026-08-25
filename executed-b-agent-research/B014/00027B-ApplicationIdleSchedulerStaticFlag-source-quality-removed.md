<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B014\00027B-ApplicationIdleSchedulerStaticFlag-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00027B-ApplicationIdleSchedulerStaticFlag-source-quality.md](00027B-ApplicationIdleSchedulerStaticFlag-source-quality.md)
- Source report SHA256 before cleanup: `6B91746D67037020B848A236FA92772E3BCCD986854E647F8DAC8F25D0924ED4`
- Cleanup generated: `2026-08-11T12:47:18Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `289-299`
- Original language: `powershell`
- Block SHA256: `DDCA97430F0FB89BBBE2D09BFB091046B88BBAFA0F50B08B3B8819922396E8FA`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/EventDispatcher.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/EventDispatcher.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004a7120-0x004a712c.ApplicationIdleTickBaseline.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/ApplicationHelper_4A6C40.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/Application.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/Event.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0066d888-0x0066da88.EventManKeyTranslationTables.md --apply --queue-timeout 240
```
