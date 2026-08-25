<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\000133-screen-dimmer-factory-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000133-screen-dimmer-factory-source-quality.md](000133-screen-dimmer-factory-source-quality.md)
- Source report SHA256 before cleanup: `FBAC10FE074953EB029053A6B14DB062350EB6A2A838D2F168FA3AF0B4DB168D`
- Cleanup generated: `2026-08-11T12:47:00Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `403-410`
- Original language: `powershell`
- Block SHA256: `43AC6C37C7DBC5CE26B5CCDE8BD0FEEC72AB8746B23377CEC6423E32886DE02A`

```powershell
python tools/validator.py --mode file --file by-memory/0x004a12b0-0x004a1360.CreateScreenDimmerFactory.md --apply
python tools/validator.py --mode file --file by-global/CreateScreenDimmer_4A12B0.md --apply
python tools/validator.py --mode file --file by-file/ScreenDimmer.md --apply
python tools/validator.py --mode file --file by-memory/-coverage-report.md --apply
python tools/memory_ranges.py report
python tools/validator.py --mode rescore --apply --lock-timeout -1
```
