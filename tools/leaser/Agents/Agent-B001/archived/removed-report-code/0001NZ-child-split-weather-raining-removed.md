<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0001NZ-child-split-weather-raining.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001NZ-child-split-weather-raining.md](0001NZ-child-split-weather-raining.md)
- Source report SHA256 before cleanup: `257081B3C256B021379DBF578A5FCECBC8FAF2C2475AE5C87DF62C3230BE70B0`
- Cleanup generated: `2026-08-11T12:46:57Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `527-536`
- Original language: `powershell`
- Block SHA256: `8F602FB1DAED47A04B82550E6F743A7483323ADA6DF4CE4763BBFEE6AAA2B5FE`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python .\tools\validator.py --mode file --file .\by-memory\0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x005c13b0-0x005c1408.WeatherLayerPaneOnTimerEvent.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x005c1410-0x005c145a.RainingLayerPaneConstructor.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x005c1460-0x005c180c.RainingLayerPaneOnPaint.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\-coverage-report.md --apply --lock-timeout -1
```
