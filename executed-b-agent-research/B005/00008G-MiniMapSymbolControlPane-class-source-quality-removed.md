<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\00008G-MiniMapSymbolControlPane-class-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00008G-MiniMapSymbolControlPane-class-source-quality.md](00008G-MiniMapSymbolControlPane-class-source-quality.md)
- Source report SHA256 before cleanup: `AFC98F3258528FEEDB85FC1C0EF000490A7BEBE7735B6571FC87BAB3B439E193`
- Cleanup generated: `2026-08-11T12:47:08Z`
- Removed executable blocks: `4`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `60-62`
- Original language: `powershell`
- Block SHA256: `0E9BD7685616E003BC0879A780E00705CDC8EE21DCE4FBCCA89DFD3BBCD45E63`

```powershell
python .\tools\validator.py --mode file --file by-class\MiniMapSymbolControlPane.md --queue-timeout 240
```

## Removed Block R002

- Original source lines: `337-346`
- Original language: `powershell`
- Block SHA256: `51E4A69C34444DAFE878345C002EBF54550F63F21B5C4EB7376EC808D5B4ABCC`

```powershell
python .\tools\validator.py --mode file --file by-class\MiniMapSymbolControlPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00453df0-0x004563b5.MiniMapRendererAndControls.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\MiniMapDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00450ca0-0x0045381b.MiniMapDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\MiniMapRenderer.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\MiniMap.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x006104f4-0x006108d4.MiniMapUiReadOnlyData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `350-353`
- Original language: `powershell`
- Block SHA256: `38E81440079A8EAD0CD0E9F967B938774EBB305DD06F578F8379C312AECB999A`

```powershell
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
python .\tools\validator.py --mode rescore --apply --queue-timeout 240
```

## Removed Block R004

- Original source lines: `357-359`
- Original language: `powershell`
- Block SHA256: `58D6736F29550C2CF7E5C58B49FC60CB5D8E956910CF0B3ECDF81205D2261485`

```powershell
rg -n "00008G|MiniMapSymbolControlPane|4560f0|SetCenterPosition" by-class\MiniMapSymbolControlPane.md by-memory\0x00453df0-0x004563b5.MiniMapRendererAndControls.md auto-generated\NexusTK\map\MiniMap.cpp auto-generated\-ag-class-coverage.md project-level\-auto-completion-stats.md
```
