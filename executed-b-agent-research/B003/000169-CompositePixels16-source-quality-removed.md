<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\000169-CompositePixels16-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000169-CompositePixels16-source-quality.md](000169-CompositePixels16-source-quality.md)
- Source report SHA256 before cleanup: `47674C67235BE4C07B0FB3EA09244019BC8D57ED601B95D01E967EFBE91375F4`
- Cleanup generated: `2026-08-11T12:47:03Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `555-584`
- Original language: `powershell`
- Block SHA256: `D8F34ADA332EED13CFC132EA323D4453A143181BB1338C176E1AD23CE9E0AFC3`

```powershell
Get-Content -LiteralPath '...\Agent-B003\goal.md'
Get-Content -LiteralPath '...\Agents\Supervisor.md'
Get-Content -LiteralPath '...\by-structure.md'
Get-Content -LiteralPath '...\inference_research.md'
Get-Content -LiteralPath '...\Agent-B003\notes.md'
Get-Content -LiteralPath '...\by-memory\0x004ba540-0x004ba6ad.CompositePixels16.md'
Get-Content -LiteralPath '...\by-memory\0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md'
Get-Content -LiteralPath '...\by-memory\0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md'
Get-Content -LiteralPath '...\by-memory\0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md'
Get-Content -LiteralPath '...\by-memory\0x004b9820-0x004ba24a.SurfacePaintHelpers.md'
Get-Content -LiteralPath '...\by-memory\0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper.md'
Get-Content -LiteralPath '...\by-file\Surface.md'
Get-Content -LiteralPath '...\by-file\GrafPort.md'
Get-Content -LiteralPath '...\by-class\GrafPort.md'
Get-Content -LiteralPath '...\by-global\SurfaceRenderCallbackTable.md'
Get-Content -LiteralPath '...\by-meta\client_new_rendering_mode.md'
Get-Content -LiteralPath '...\by-file\BowGaugeObjectPane.md'
Get-Content -LiteralPath '...\by-file\TextEditPane.md'
Get-Content -LiteralPath '...\by-file\Palette.md'
Get-Content -LiteralPath '...\by-file\PaletteLib.md'
Get-Content -LiteralPath '...\by-global\g_pPaletteLib.md'
Get-Content -LiteralPath '...\by-memory\0x00542ac0-0x00543149.DLPaletteMethodCluster.md'
Get-Content -LiteralPath '...\by-class\PaletteLib.md'
Get-Content -LiteralPath '...\by-class\DLPalette.md'
Select-String -LiteralPath '...\auto-generated\-ag-memory-coverage.md','...\project-level\-auto-completion-stats.md','...\by-memory\-coverage-report.md' -Pattern '000169|004ba540|CompositePixels16|CompositePixels' -Context 1,1
Get-Item -LiteralPath '...\auto-generated\NexusTK\render\Surface.cpp','...\auto-generated\NexusTK\render\GrafPort.cpp','...\auto-generated\NexusTK\map\MapPane.cpp'
Select-String -LiteralPath '...\simroot_v2\class_BowGaugeObjectPane.cpp','...\simroot_v2\class_TextEditPane.cpp' -Pattern 'CompositePixels|4BA540|004ba540|Composite' -Context 3,20
Invoke-WebRequest -UseBasicParsing -Uri 'http://127.0.0.1:13337/mcp' ... # MCP unavailable
```

## Removed Block R002

- Original source lines: `603-616`
- Original language: `powershell`
- Block SHA256: `3F33FF4DFD08FC0C56CF703F8243DC888BE425C79839074CCBCC3F40E5867F7B`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python tools\validator.py --mode file --file by-memory\0x004ba540-0x004ba6ad.CompositePixels16.md --apply
python tools\validator.py --mode file --file by-class\GrafPort.md --apply
python tools\validator.py --mode file --file by-file\GrafPort.md --apply
python tools\validator.py --mode file --file by-file\Surface.md --apply
python tools\validator.py --mode file --file by-memory\0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md --apply
python tools\validator.py --mode file --file by-file\BowGaugeObjectPane.md --apply
python tools\validator.py --mode file --file by-file\TextEditPane.md --apply
python tools\validator.py --mode file --file by-memory\-coverage-report.md --apply
python tools\validator.py --mode autogen --apply
python tools\validator.py --mode rescore --apply
rg -n "000169|004ba540|CompositePixels|GrafPort::CompositePixels|BowGaugeObjectPane::CompositePixels|dword_69B3FC" by-memory by-class by-file by-global auto-generated project-level -g "*.md" -g "*.cpp"
```
