<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\00022H-RectBoundsQuarterScaleHelpers-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00022H-RectBoundsQuarterScaleHelpers-source-quality.md](00022H-RectBoundsQuarterScaleHelpers-source-quality.md)
- Source report SHA256 before cleanup: `EA04992B25C624C8A74ED002E3DD9744059557B5F72AD0AB00E236973148B7C8`
- Cleanup generated: `2026-08-11T12:46:58Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `380-393`
- Original language: `powershell`
- Block SHA256: `2F39492FAEDD5FD3D0B2CBB6239212E4589AA9E572B3A2E574E2A64567713264`

```powershell
Push-Location source-3\project-documentation
python .\tools\validator.py --mode file --file by-memory\0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-file\RectBounds.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-class\RectBounds.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-type\by-struct\RectBoundsLayout.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x004b78d0-0x004b7ae8.RectBoundsMethods.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x004b7c30-0x004b7f87.RectGeometryHelpers.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\-ignored.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode rescore --apply --queue-timeout 240 --lock-timeout -1
python .\tools\memory_ranges.py report
Pop-Location
```
