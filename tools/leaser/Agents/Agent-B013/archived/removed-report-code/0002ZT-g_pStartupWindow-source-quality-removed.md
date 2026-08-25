<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B013\0002ZT-g_pStartupWindow-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002ZT-g_pStartupWindow-source-quality.md](0002ZT-g_pStartupWindow-source-quality.md)
- Source report SHA256 before cleanup: `C9DA310FA86D743998D05FCB5B566EB551473D996C6B3DC7B77C942F01EB5536`
- Cleanup generated: `2026-08-11T12:47:18Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `270-274`
- Original language: `powershell`
- Block SHA256: `B4AFFF44887D84F43E1B1C8BC1DB1912EE77F9C7AD4089E6B9D1399DB9623947`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x0069bac8-0x0069bacc.g_pStartupWindow.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-global/g_pStartupWindow.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md --apply --queue-timeout 240 --wait-generated
```
