<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B011\0001O3-SwallowLayerPaneRawFlightHelpers-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001O3-SwallowLayerPaneRawFlightHelpers-source-quality.md](0001O3-SwallowLayerPaneRawFlightHelpers-source-quality.md)
- Source report SHA256 before cleanup: `8FA295BF1D79CF7CF4B0F006AB5F901AF5AA0E8F652AB455C10F7FD9FA432E6D`
- Cleanup generated: `2026-08-11T12:47:16Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `296-304`
- Original language: `powershell`
- Block SHA256: `E25CC06462390A16AC5A5887A5D0251274C2BF32A800ED4CB9F7D23AAD315DFF`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class\SwallowLayerPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\SwallowLayerPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\WeatherLayerPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005c2230-0x005c299f.SwallowLayerPaneCore.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md --apply --queue-timeout 240
```
