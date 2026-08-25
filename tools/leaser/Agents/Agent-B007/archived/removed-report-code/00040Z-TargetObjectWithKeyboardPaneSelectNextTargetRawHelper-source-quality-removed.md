<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B007\00040Z-TargetObjectWithKeyboardPaneSelectNextTargetRawHelper-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00040Z-TargetObjectWithKeyboardPaneSelectNextTargetRawHelper-source-quality.md](00040Z-TargetObjectWithKeyboardPaneSelectNextTargetRawHelper-source-quality.md)
- Source report SHA256 before cleanup: `5BD1CD38F8E224682D7536B08848B15080A3A7E6FC0EDB7F6DFCAF7EF657B184`
- Cleanup generated: `2026-08-11T12:47:12Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `323-329`
- Original language: `powershell`
- Block SHA256: `E31DC11F1D800DD898CDFC84A3E4C3B84A4407699667A63D76F194110381E0C8`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x005b0640-0x005b06a8.TargetObjectWithKeyboardPaneSelectNextTargetRawHelper.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x005b05d0-0x005b06ef.TargetObjectWithKeyboardPaneNavigationRawHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\TargetObjectWithKeyboardPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\TargetSelectionInputPanes.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent.md --apply --queue-timeout 240
```
