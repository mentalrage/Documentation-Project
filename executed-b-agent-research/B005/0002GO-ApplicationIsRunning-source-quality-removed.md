<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\0002GO-ApplicationIsRunning-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002GO-ApplicationIsRunning-source-quality.md](0002GO-ApplicationIsRunning-source-quality.md)
- Source report SHA256 before cleanup: `AE1011899B5663BAB7839FD3B96125A6BDFFA531FF6865D867243BC068316B52`
- Cleanup generated: `2026-08-11T12:47:09Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `205-216`
- Original language: `powershell`
- Block SHA256: `9C7453954889EEA662303F39077ADA75CFC4D418C81F51957B7B2C62D75503F8`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004651e0-0x004651e7.ApplicationIsRunning.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\Application.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\Application.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00463310-0x004674ed.ApplicationLifecycle.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00463310-0x0046396e.ApplicationConstructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004669c0-0x00466a69.BaramAppOnActivate.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00466a70-0x00466b23.BaramAppOnDeactivate.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00556910-0x00557132.ScreenPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\ScreenPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\ScreenPane.md --apply --queue-timeout 240
```
