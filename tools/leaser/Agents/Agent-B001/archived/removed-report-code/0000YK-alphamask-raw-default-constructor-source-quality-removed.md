<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0000YK-alphamask-raw-default-constructor-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000YK-alphamask-raw-default-constructor-source-quality.md](0000YK-alphamask-raw-default-constructor-source-quality.md)
- Source report SHA256 before cleanup: `74774F941AA7B581D7DDE0C034E16294C137E5124E2B2AD5E11509674F5907B2`
- Cleanup generated: `2026-08-11T12:46:56Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `203-208`
- Original language: `powershell`
- Block SHA256: `E8716917CD2BFBD1A2C12CFCFFF5CE036AE23B6BAFD7D3D91A29EC10ADCF0AEB`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\memory_ranges.py report
python .\tools\validator.py --mode rescore --apply --lock-timeout -1
```
