<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\000167-SurfaceSpriteBlitHelper-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000167-SurfaceSpriteBlitHelper-source-quality.md](000167-SurfaceSpriteBlitHelper-source-quality.md)
- Source report SHA256 before cleanup: `519A5FAAEE00D9BF30020820384AEAFFDA2FABC0D8A8583119D9F2C456C49537`
- Cleanup generated: `2026-08-11T12:47:03Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `539-559`
- Original language: `powershell`
- Block SHA256: `8D40E49C7638838D2E29F2CF244972986CC39361EDE79B22EF8EB5D327783807`

```powershell
Get-Content -LiteralPath '...\Agent-B003\goal.md'
Get-Content -LiteralPath '...\Agents\Supervisor.md'
Get-Content -LiteralPath '...\Agent-B003\notes.md'
Get-Content -LiteralPath '...\by-memory\0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md'
rg -n "000167|SurfaceSpriteBlit|0x004ba250|dword_69B3E8|69B3E8|client_new_rendering_mode|DrawSpriteAtPosition|SpriteBlit" '...\project-documentation'
Get-Content -LiteralPath '...\by-file\Surface.md'
Get-Content -LiteralPath '...\by-file\GrafPort.md'
Get-Content -LiteralPath '...\by-class\GrafPort.md'
Get-Content -LiteralPath '...\by-global\SurfaceRenderCallbackTable.md'
Get-Content -LiteralPath '...\by-meta\client_new_rendering_mode.md'
Get-Content -LiteralPath '...\by-memory\0x004b9820-0x004ba24a.SurfacePaintHelpers.md'
Get-Content -LiteralPath '...\by-memory\0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper.md'
Get-Content -LiteralPath '...\by-memory\0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md'
Get-Content -LiteralPath '...\by-memory\0x004ba540-0x004ba6ad.CompositePixels16.md'
Get-Content -LiteralPath '...\by-memory\0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md'
Select-String -LiteralPath '...\auto-generated\-ag-memory-coverage.md' -Pattern '000167|004ba250|SurfaceSpriteBlitHelper' -Context 2,2
Select-String -LiteralPath '...\project-level\-auto-completion-stats.md' -Pattern '000167|SurfaceSpriteBlitHelper|004ba250' -Context 1,1
Select-String -LiteralPath '...\by-memory\-coverage-report.md' -Pattern '000167|004ba250' -Context 2,2
Get-Content -LiteralPath '...\Agent-B002\research\executed\0003XE-SurfaceTileBufferBlitRaw-goal2-reanalysis.md'
```

## Removed Block R002

- Original source lines: `576-587`
- Original language: `powershell`
- Block SHA256: `7386B0694C031DB76C9AA6B42ECF18F4BC35AA44C8F52313F6C0B810AA1D1318`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python tools\validator.py --mode file --file by-memory\0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md --apply
python tools\validator.py --mode file --file by-class\GrafPort.md --apply
python tools\validator.py --mode file --file by-file\GrafPort.md --apply
python tools\validator.py --mode file --file by-file\Surface.md --apply
python tools\validator.py --mode file --file by-global\SurfaceRenderCallbackTable.md --apply
python tools\validator.py --mode file --file by-memory\-coverage-report.md --apply
python tools\validator.py --mode autogen --apply
python tools\validator.py --mode rescore --apply
rg -n "000167|004ba250|DrawSpriteAtPosition|GrafPort::BlitSurface|g_pfnBlitSprite|dword_69B3E8" by-memory by-class by-file by-global auto-generated project-level -g "*.md" -g "*.cpp"
```
