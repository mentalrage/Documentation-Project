<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\00027I-MapPaneCoordinateClampConstants-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00027I-MapPaneCoordinateClampConstants-source-quality.md](00027I-MapPaneCoordinateClampConstants-source-quality.md)
- Source report SHA256 before cleanup: `12838D310BE58E9A5BF72AB7B4CE86105DD62657BD5E4F21C642E3D104D13D7B`
- Cleanup generated: `2026-08-11T12:47:01Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `563-580`
- Original language: `powershell`
- Block SHA256: `CB91FA79839D15D9A9A3E345C336DCD6962D7391AB8263C34CE92F02B3E85FED`

```powershell
Set-Location E:\NTK\GhidraBridge\source-3\project-documentation
python .\tools\validator.py --mode file --file .\by-memory\0x0066daa2-0x0066daec.LegacyAssetRemapConstantsDataIsland.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x0066daa2-0x0066daa4.MapTileHeightTrailingPadding.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x0066daa4-0x0066dabc.UnreferencedLegacyAssetRemapTriplets.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x0066dabc-0x0066dad4.MapPaneLegacyMapTileRemapConstants.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x0066dad4-0x0066dae0.ItemObjImageLibLegacyItemRemapConstants.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x0066dae0-0x0066daec.UnreferencedLegacyAssetRemapTailTriplet.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-file\MapPane.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-class\MapPane.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-file\ItemObjImageLib.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-item\GetItemGlyphBounds_004DF460.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-global\MapTilePixelDimensions.md --apply --lock-timeout -1
python .\tools\validator.py --mode autogen --apply --lock-timeout -1
python .\tools\validator.py --mode rescore --apply --lock-timeout -1
python .\tools\validator.py --mode memory_ranges --apply --lock-timeout -1
```
