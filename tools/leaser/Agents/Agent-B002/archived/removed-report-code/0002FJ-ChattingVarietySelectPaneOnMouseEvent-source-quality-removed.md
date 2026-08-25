<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0002FJ-ChattingVarietySelectPaneOnMouseEvent-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002FJ-ChattingVarietySelectPaneOnMouseEvent-source-quality.md](0002FJ-ChattingVarietySelectPaneOnMouseEvent-source-quality.md)
- Source report SHA256 before cleanup: `B4009622ED67B8D1AC188C023F5F63225022B01D5788CE7F00640F76ED3347B4`
- Cleanup generated: `2026-08-11T12:47:02Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `359-363`
- Original language: `powershell`
- Block SHA256: `61F39C536CEC693E83EAC5E2C71FB60B8D4699BB959EA0FFCC7CC4E18DB80BAF`

```powershell
$idb = 'E:\NTK\Resources\NexusTK\NexusTK.exe.i64'
$probe = [System.IO.File]::Open($idb, [System.IO.FileMode]::Open, [System.IO.FileAccess]::Read, [System.IO.FileShare]::None)
try { if (-not $probe.CanRead) { throw 'Exclusive canonical-IDB probe is not readable.' } } finally { $probe.Dispose() }
```

## Removed Block R002

- Original source lines: `369-385`
- Original language: `powershell`
- Block SHA256: `4B9E0DFBB0FC3555F6974B6ACD533D5E348FD86BAA843F5B6C5D201A886E17B5`

```powershell
$preItem = Get-Item -LiteralPath $idb
$prePath = $preItem.FullName
$preSize = $preItem.Length
$preSha = (Get-FileHash -LiteralPath $idb -Algorithm SHA256).Hash
$preMtime = $preItem.LastWriteTimeUtc
$stamp = Get-Date -Format 'yyyyMMdd-HHmmss-fffffff'
$backup = "$idb.bak-UID0002FJ-prestate-$stamp-$($preSha.Substring(0,16))"
if (Test-Path -LiteralPath $backup) { throw 'UID0002FJ backup destination already exists.' }
Copy-Item -LiteralPath $idb -Destination $backup -ErrorAction Stop
$backupItem = Get-Item -LiteralPath $backup
$backupSha = (Get-FileHash -LiteralPath $backup -Algorithm SHA256).Hash
if ($backupItem.Length -ne $preSize -or $backupSha -ne $preSha) { throw 'Backup is not byte-identical to P0.' }
$closedAgain = Get-Item -LiteralPath $idb
$closedAgainSha = (Get-FileHash -LiteralPath $idb -Algorithm SHA256).Hash
if ($closedAgain.FullName -ne $prePath -or $closedAgain.Length -ne $preSize -or $closedAgain.LastWriteTimeUtc -ne $preMtime -or $closedAgainSha -ne $preSha) { throw 'Canonical disk changed during backup creation.' }
```
