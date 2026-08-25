<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0003XE-SurfaceTileBufferBlitRaw-goal2-reanalysis.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003XE-SurfaceTileBufferBlitRaw-goal2-reanalysis.md](0003XE-SurfaceTileBufferBlitRaw-goal2-reanalysis.md)
- Source report SHA256 before cleanup: `839C792DC19E76028998C0D40DADBBC5D83CB1116E8D74E15721745CA5FE9077`
- Cleanup generated: `2026-08-11T12:47:03Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `299-306`
- Original language: `powershell`
- Block SHA256: `DAC71CC553D57369794B349D13120D361F7AE17B7DD071DFDBF9D8E5FC6ABFD5`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python tools\validator.py --mode file --file by-memory\0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw.md --apply
python tools\validator.py --mode file --file by-memory\0x004b8bf0-0x004bb8c4.GrafPort.md --apply
python tools\validator.py --mode file --file by-file\Surface.md --apply
python tools\validator.py --mode file --file by-global\SurfaceRenderCallbackTable.md --apply
rg -n "0003XE|004bb260|004bb2d7|004bb2d5" by-memory by-file by-global -g "*.md"
```

## Removed Block R002

- Original source lines: `310-313`
- Original language: `powershell`
- Block SHA256: `9FEC5BE65E8DD97FC187261870A8D401F432EFD881112E04217FF5F8F0099FD3`

```powershell
$body = @{jsonrpc='2.0'; id=1; method='tools/list'; params=@{}} | ConvertTo-Json -Depth 8
Invoke-WebRequest -UseBasicParsing -Uri http://127.0.0.1:13337/mcp -Method Post -ContentType 'application/json' -Headers @{Accept='application/json, text/event-stream'} -Body $body
```
