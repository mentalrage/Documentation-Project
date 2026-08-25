<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B007\0003A2-ScreenPanePaletteVisibleTilesRedrawRaw-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003A2-ScreenPanePaletteVisibleTilesRedrawRaw-source-quality.md](0003A2-ScreenPanePaletteVisibleTilesRedrawRaw-source-quality.md)
- Source report SHA256 before cleanup: `E15B386EE5265FAF7C8E86A52570FBDE7B9234725E5FC7BFCA2507CB7C1CDEDF`
- Cleanup generated: `2026-08-11T12:47:12Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `541-551`
- Original language: `powershell`
- Block SHA256: `7E6B7A7840714795E7487E6B91D41D41DD8D2C01B17E90BEF611E219C03BA268`

```powershell
python .\source-3\project-documentation\tools\validator.py --mode file --file by-memory\0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw.md --apply --queue-timeout 240
python .\source-3\project-documentation\tools\validator.py --mode file --file by-file\ScreenPane.md --apply --queue-timeout 240
python .\source-3\project-documentation\tools\validator.py --mode file --file by-class\ScreenPane.md --apply --queue-timeout 240
python .\source-3\project-documentation\tools\validator.py --mode file --file by-memory\0x00556910-0x00557132.ScreenPane.md --apply --queue-timeout 240
python .\source-3\project-documentation\tools\validator.py --mode file --file by-memory\0x00557140-0x00559aef.SurfacePresentation.md --apply --queue-timeout 240
python .\source-3\project-documentation\tools\validator.py --mode file --file by-memory\0x005051c0-0x00505228.DrawVisibleTilesHelper.md --apply --queue-timeout 240
python .\source-3\project-documentation\tools\validator.py --mode file --file by-memory\0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md --apply --queue-timeout 240
python .\source-3\project-documentation\tools\validator.py --mode file --file by-global\g_pGeneralPurposePanel.md --apply --queue-timeout 240
python .\source-3\project-documentation\tools\validator.py --mode file --file by-global\g_activeMapPane.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `555-557`
- Original language: `powershell`
- Block SHA256: `DC3761FF5CC171F63D7B667331A24BDCD58201159E17C46DC001A15032FFAA06`

```powershell
python .\source-3\project-documentation\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240
```
