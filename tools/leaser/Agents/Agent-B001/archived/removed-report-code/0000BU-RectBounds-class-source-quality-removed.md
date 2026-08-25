<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0000BU-RectBounds-class-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000BU-RectBounds-class-source-quality.md](0000BU-RectBounds-class-source-quality.md)
- Source report SHA256 before cleanup: `DE7D5C312B3790004CB859973FA9C63C57396C10154F430B590B4C7F17FE3AEF`
- Cleanup generated: `2026-08-11T12:46:56Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `662-674`
- Original language: `powershell`
- Block SHA256: `200FED9D2B8F0C9A2A35D66E90F5AF14025C50475F930607BC3DEAEA26E0C639`

```powershell
python .\tools\validator.py --mode file --file by-class\RectBounds.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\RectBounds.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-struct\RectBoundsLayout.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004b78d0-0x004b7ae8.RectBoundsMethods.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004b7910-0x004b795e.RectBoundsInset.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004b7ca0-0x004b7cb6.RectArea.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004b7c30-0x004b7f87.RectGeometryHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md --apply --queue-timeout 240
```
