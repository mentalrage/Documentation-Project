<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\000294-g_pApplication-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000294-g_pApplication-source-quality.md](000294-g_pApplication-source-quality.md)
- Source report SHA256 before cleanup: `9327CB22B41BD126118D4977A33D61E888D378CC8952115D407327D000370DCE`
- Cleanup generated: `2026-08-11T12:46:58Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `393-402`
- Original language: `powershell`
- Block SHA256: `30CB590943B8F86BA815A0C1F284AD0C75863C4F28BD70CFC7F82718E13A4CB8`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0067ab1c-0x0067ab20.g_pApplication.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\Application.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\Application.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00463310-0x004674ed.ApplicationLifecycle.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00463310-0x0046396e.ApplicationConstructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00463970-0x004639c4.ApplicationDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0066d000-0x0069d000.DataSection.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0067ab20-0x0067ab24.g_pDirectX.md --apply --queue-timeout 240
```
