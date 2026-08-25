<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0002BU-0002BV-0002C6-0002C7-MidiSMFParserStreamSourceQuality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002BU-0002BV-0002C6-0002C7-MidiSMFParserStreamSourceQuality.md](0002BU-0002BV-0002C6-0002C7-MidiSMFParserStreamSourceQuality.md)
- Source report SHA256 before cleanup: `950E7F284AD2DCE066F508337AF448DD3B5EA3DF3F6391BD58E834D3D808D401`
- Cleanup generated: `2026-08-11T12:46:58Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `882-898`
- Original language: `powershell`
- Block SHA256: `1F0BE3F2BFAE0CB778F29299DEE05BDCF8D0CE7E5EFDE4B7942C88300C288B3D`

```powershell
Get-Content -Raw 'E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\goal.md'
Get-Content -Raw 'E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Supervisor.md'
Get-Content -Raw 'E:\NTK\GhidraBridge\.codex\AGENTS.md'
Get-Content -Raw 'source-3\project-documentation\by-structure.md'
Get-Content -Raw 'source-3\project-documentation\tools\leaser\Agents\Agent-B001\inference_research.md'
Get-Content -Raw 'source-3\project-documentation\by-project-structure\proposed-source-tree.md'
Invoke-WebRequest -UseBasicParsing -Uri 'http://127.0.0.1:13337/mcp' -Method Post ...
Get-Content -Raw '<target and support docs listed in this report>'
rg -n '0002BU|0002BV|0002C6|0002C7|...' 'source-3\project-documentation\by-memory\-coverage-report.md'
rg -n '0002BU|0002BV|0002C6|0002C7|...' 'source-3\project-documentation\auto-generated\-ag-memory-coverage.md'
Get-Item 'source-3\project-documentation\auto-generated\NexusTK\audio\MidiPlayer.cpp'
Get-ChildItem 'source-3\project-documentation\tools\leaser\Agents\Agent-B001\research' -File | Where-Object { $_.Name -like '0002BU-0002BV-0002C6-0002C7-*' }
$bytes=[System.IO.File]::ReadAllBytes((Resolve-Path 'source-3\project-documentation\tools\leaser\Agents\Agent-B001\research\0002BU-0002BV-0002C6-0002C7-MidiSMFParserStreamSourceQuality.md')); $bytes | Where-Object { $_ -gt 127 } | Select-Object -First 5
Test-Path 'source-3\project-documentation\tools\leaser\Agents\Agent-B001\research\0002BU-0002BV-0002C6-0002C7-MidiSMFParserStreamSourceQuality.md'
git status --short -- 'source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/0002BU-0002BV-0002C6-0002C7-MidiSMFParserStreamSourceQuality.md'
```
