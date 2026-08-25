<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0001CV-0001CX-0001CY-0001D0-NumberInputDialog-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001CV-0001CX-0001CY-0001D0-NumberInputDialog-source-quality.md](0001CV-0001CX-0001CY-0001D0-NumberInputDialog-source-quality.md)
- Source report SHA256 before cleanup: `829A03668825F661FD1FAB7EF32A3BC97F59529D131B6F8F575AC2EC7F533044`
- Cleanup generated: `2026-08-11T12:47:01Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `400-415`
- Original language: `text`
- Block SHA256: `57C1D90D3A0F42831693EFE771B539E3ACF5AABB3A40903F55EC4CC51BFE405C`

```text
Command:
$body = @{jsonrpc='2.0'; id=1; method='tools/list'; params=@{}} | ConvertTo-Json -Depth 8
try {
  $r = Invoke-WebRequest -UseBasicParsing -Uri 'http://127.0.0.1:13337/mcp' -Method Post -ContentType 'application/json' -Headers @{Accept='application/json, text/event-stream'} -Body $body -TimeoutSec 8
  $r.StatusCode
  $r.Content
} catch {
  'IDA_MCP_ERROR'
  $_.Exception.Message
}

Result:
IDA_MCP_ERROR
Unable to connect to the remote server
```

## Removed Block R002

- Original source lines: `419-427`
- Original language: `text`
- Block SHA256: `FCB75DDBF23689DE8D13887BF711AD161CCB308FB874C659C0516E9C25C196E7`

```text
Command:
Get-Item -LiteralPath 'source-3/project-documentation/auto-generated/NexusTK/ui/dialogs/NumberInputDialog.cpp' |
  Select-Object FullName,Length,LastWriteTime

Result:
FullName: E:\NTK\GhidraBridge\source-3\project-documentation\auto-generated\NexusTK\ui\dialogs\NumberInputDialog.cpp
Length: 0
```

## Removed Block R003

- Original source lines: `431-447`
- Original language: `text`
- Block SHA256: `902F2CB61FDDDBFCF220C2A4DDE5A9C4ABD57AE79A541EA29D706A954E70E4D5`

```text
Command:
$path = 'source-3/project-documentation/tools/leaser/Agents/Agent-B002/research/0001CV-0001CX-0001CY-0001D0-NumberInputDialog-source-quality.md'
$item = Get-Item -LiteralPath $path
$bytes = [System.IO.File]::ReadAllBytes($item.FullName)
$nonAscii = ($bytes | Where-Object { $_ -gt 127 }).Count
$item.FullName
$item.Length
"NonAsciiByteCount=$nonAscii"
(Get-ChildItem -LiteralPath 'source-3/project-documentation/tools/leaser/Agents/Agent-B002/research' -Filter '0001CV-0001CX-0001CY-0001D0-*' | Measure-Object).Count

Result:
E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\0001CV-0001CX-0001CY-0001D0-NumberInputDialog-source-quality.md
31469
NonAsciiByteCount=0
1
```
