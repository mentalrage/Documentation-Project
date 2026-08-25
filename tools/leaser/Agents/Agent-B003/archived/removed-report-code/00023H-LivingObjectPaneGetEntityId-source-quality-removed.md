<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\00023H-LivingObjectPaneGetEntityId-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00023H-LivingObjectPaneGetEntityId-source-quality.md](00023H-LivingObjectPaneGetEntityId-source-quality.md)
- Source report SHA256 before cleanup: `53B438C742419EB60FC2E9637A9178D1A332B57190BA34702A96664574C7B682`
- Cleanup generated: `2026-08-11T12:47:04Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `510-515`
- Original language: `powershell`
- Block SHA256: `5F1D54622382C60F6B37464260760C2810437984B2BA078483BB56BECED571E9`

```powershell
Get-Content -LiteralPath 'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00538bb0-0x00538bb7.LivingObjectPaneGetEntityId.md'
Get-Content -LiteralPath 'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005387b0-0x00538baa.EffectObjectPaneCore.md'
Get-Content -LiteralPath 'E:\NTK\GhidraBridge\source-3\project-documentation\by-class\EffectObjectPane.md'
rg -n "00023H|0x00538bb0|LivingObjectPaneGetEntityId|EffectObjectPaneIsLooping" E:\NTK\GhidraBridge\source-3\project-documentation
```

## Removed Block R002

- Original source lines: `519-522`
- Original language: `powershell`
- Block SHA256: `AD739CAB73DD370D962E9A5B8B41CCE9B9449AD1775257C4CCD1E507D9E06CCB`

```powershell
$body = @{jsonrpc='2.0'; id=1; method='tools/list'; params=@{}} | ConvertTo-Json -Depth 8
Invoke-WebRequest -UseBasicParsing -Uri 'http://127.0.0.1:13337/mcp' -Method Post -ContentType 'application/json' -Headers @{Accept='application/json, text/event-stream'} -Body $body -TimeoutSec 5
```

## Removed Block R003

- Original source lines: `528-536`
- Original language: `powershell`
- Block SHA256: `ECE32F2A69941AC133D9A76CF5183ECBFB27E8DBA48B0E4812EB2E90D7920A63`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md --apply --queue-timeout 180
python .\tools\validator.py --mode file --file by-class\EffectObjectPane.md --apply --queue-timeout 180
python .\tools\validator.py --mode file --file by-class\LivingObjectPane.md --apply --queue-timeout 180
python .\tools\validator.py --mode file --file by-file\LivingObjectPane.md --apply --queue-timeout 180
python .\tools\validator.py --mode file --file by-memory\0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md --apply --queue-timeout 180
python .\tools\validator.py --mode file --file by-memory\0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md --apply --queue-timeout 180
python .\tools\validator.py --mode file --file by-memory\0x005a2e00-0x005a36de.LivingObjectPaneProcessMovement.md --apply --queue-timeout 180
```
