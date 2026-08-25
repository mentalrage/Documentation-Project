<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B007\0000XO-MiniMapRendererAndControls-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000XO-MiniMapRendererAndControls-source-quality.md](0000XO-MiniMapRendererAndControls-source-quality.md)
- Source report SHA256 before cleanup: `2C616B82BFC2101ECB6BD55F02C2DFF1FBB69C19593DE216BEFA2156F8C5FE89`
- Cleanup generated: `2026-08-11T12:47:12Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `447-459`
- Original language: `powershell`
- Block SHA256: `92A3925D051EC338E35A42988C21821FC61044372BA13309FFCA9F7EF89AA47D`

```powershell
python tools\validator.py --mode file --file by-memory\0x00453df0-0x004563b5.MiniMapRendererAndControls.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-class\MiniMapRenderer.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-class\MiniMapImageControlPane.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-class\MiniMapSymbolControlPane.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-file\MiniMap.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-memory\0x00450ca0-0x00453de0.MiniMapDialog.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-class\MiniMapDialog.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-memory\0x00457620-0x00457a5d.MiniMapFileLoaderHelpers.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-memory\0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-memory\0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240
```
