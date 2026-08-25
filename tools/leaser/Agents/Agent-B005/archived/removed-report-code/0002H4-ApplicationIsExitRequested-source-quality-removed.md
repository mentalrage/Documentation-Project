<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\0002H4-ApplicationIsExitRequested-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002H4-ApplicationIsExitRequested-source-quality.md](0002H4-ApplicationIsExitRequested-source-quality.md)
- Source report SHA256 before cleanup: `0AE7C63DBC2A1532E282C072F142200294BE34585006A6329F335948ABE377C8`
- Cleanup generated: `2026-08-11T12:47:09Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `510-534`
- Original language: `powershell`
- Block SHA256: `B5DA60A675B02214DECC802564BD03B448E198902A4E08050F4D6EF5F04FC44A`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00464f40-0x00464f47.ApplicationIsExitRequested.md --apply --queue-timeout 240
# exit code 0; scanned markdown files: 1; ok: 1

python .\tools\validator.py --mode file --file by-class\Application.md --apply --queue-timeout 240
# exit code 0; scanned markdown files: 1; ok: 1

python .\tools\validator.py --mode file --file by-file\Application.md --apply --queue-timeout 240
# exit code 0; scanned markdown files: 1; ok: 1

python .\tools\validator.py --mode file --file by-memory\0x00463310-0x004674ed.ApplicationLifecycle.md --apply --queue-timeout 240
# exit code 0; scanned markdown files: 1; ok: 1

python .\tools\validator.py --mode file --file by-memory\0x00464e40-0x00464f34.ApplicationRequestExit.md --apply --queue-timeout 240
# exit code 0; scanned markdown files: 1; ok: 1

python .\tools\validator.py --mode file --file by-memory\0x00463310-0x0046396e.ApplicationConstructor.md --apply --queue-timeout 240
# exit code 0; scanned markdown files: 1; ok: 1

python .\tools\validator.py --mode file --file by-memory\0x004a6a80-0x004a82a9.EventDispatcher.md --apply --queue-timeout 240
# exit code 0; scanned markdown files: 1; ok: 1

python .\tools\validator.py --mode file --file by-memory\0x00556910-0x00557132.ScreenPane.md --apply --queue-timeout 240
# exit code 0; scanned markdown files: 1; ok: 1
```
