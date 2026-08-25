<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0002KF-0002KH-0002KI-parcelpane-slot-animation-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002KF-0002KH-0002KI-parcelpane-slot-animation-source-quality.md](0002KF-0002KH-0002KI-parcelpane-slot-animation-source-quality.md)
- Source report SHA256 before cleanup: `600EC80A004669749765C8191AA27C289A5EBFBCFD32DCD06DEF7521E784DB90`
- Cleanup generated: `2026-08-11T12:46:58Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `255-263`
- Original language: `powershell`
- Block SHA256: `27A3E0C8B57A11928557B9CB3C5309C1D3F34D97BFB90B606A9EA982CACE1460`

```powershell
Get-Content -LiteralPath 'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00546810-0x00546888.ParcelPaneProcessSlotAnimations.md'
Get-Content -LiteralPath 'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00546970-0x005469db.ParcelPaneUpdateAnimationCounter.md'
Get-Content -LiteralPath 'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005469e0-0x00546aab.ParcelPaneGetButtonFrameIndex.md'
Get-Content -LiteralPath 'E:\NTK\GhidraBridge\source-3\project-documentation\by-type\by-struct\ParcelNotificationPaneLayouts.md'
Get-Content -LiteralPath 'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00621bb0-0x00621d50.ParcelNotificationVtableData.md'
Select-String -LiteralPath 'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md' -Pattern '00546810|00546970|005469e0|00546aac'
'["0xc8","0x64","0x78","0x6b","0xcb","0xa0","0xa4","0xf8","0xf9","0xfa","0xfb","0xfc","0xfd","0xfe","0xff","0x100","0x110","0x120","0x121"]' | python 'E:\NTK\GhidraBridge\source-3\project-documentation\tools\int_convert.py' --pretty
```
