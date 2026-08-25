<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B009\0002W1-g_fpsLogEnabled-empty-emitter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002W1-g_fpsLogEnabled-empty-emitter-source-quality.md](0002W1-g_fpsLogEnabled-empty-emitter-source-quality.md)
- Source report SHA256 before cleanup: `913FE81512F24441A74ED4779833ECE771C0A7F1745FB6AC9E4B16048DE4A9BB`
- Cleanup generated: `2026-08-11T12:47:14Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `409-419`
- Original language: `powershell`
- Block SHA256: `0A0C140697D554E00DD008377E5499A5CB99E60358B67D437D97BABE4298F315`

```powershell
$canonical = 'E:\NTK\Resources\NexusTK\NexusTK.exe.i64'
$stamp = Get-Date -Format 'yyyyMMdd-HHmmss'
$backup = "$canonical.bak-UID0002W1-prestate-$stamp"
Copy-Item -LiteralPath $canonical -Destination $backup -ErrorAction Stop
$canonicalItem = Get-Item -LiteralPath $canonical
$backupItem = Get-Item -LiteralPath $backup
$canonicalHash = (Get-FileHash -LiteralPath $canonical -Algorithm SHA256).Hash
$backupHash = (Get-FileHash -LiteralPath $backup -Algorithm SHA256).Hash
if (($canonicalItem.Length -ne $backupItem.Length) -or ($canonicalHash -cne $backupHash)) { throw 'UID0002W1 prestate backup mismatch; abort before IDA mutation.' }
```

## Removed Block R002

- Original source lines: `473-481`
- Original language: `powershell`
- Block SHA256: `F68A6F05E2B2D8570E920589763673C896A5930419C5E3F1D7AF293A8870A246`

```powershell
$workerPid = [int]'<gate2b-worker-pid>'
Stop-Process -Id $workerPid -Force -ErrorAction Stop
for ($i = 0; $i -lt 50 -and (Get-Process -Id $workerPid -ErrorAction SilentlyContinue); $i++) { Start-Sleep -Milliseconds 100 }
if (Get-Process -Id $workerPid -ErrorAction SilentlyContinue) { throw 'UID0002W1 dirty worker did not stop; halt without save.' }
$currentItem = Get-Item -LiteralPath $canonical
$currentHash = (Get-FileHash -LiteralPath $canonical -Algorithm SHA256).Hash
if (($currentItem.Length -ne $canonicalItem.Length) -or ($currentHash -cne $canonicalHash)) { throw 'UID0002W1 no-save rollback disk identity drifted; halt.' }
```

## Removed Block R003

- Original source lines: `485-494`
- Original language: `powershell`
- Block SHA256: `9284C5E1D581622117F9A28E44A089A82008853EAB11B280D348850C750C69A5`

```powershell
$persistWorkerPid = [int]'<persist-worker-pid>'
Stop-Process -Id $persistWorkerPid -Force -ErrorAction Stop
for ($i = 0; $i -lt 50 -and (Get-Process -Id $persistWorkerPid -ErrorAction SilentlyContinue); $i++) { Start-Sleep -Milliseconds 100 }
if (Get-Process -Id $persistWorkerPid -ErrorAction SilentlyContinue) { throw 'UID0002W1 persistence worker did not stop; halt before restore.' }
Copy-Item -LiteralPath '<backup-path>' -Destination $canonical -Force -ErrorAction Stop
$restoredItem = Get-Item -LiteralPath $canonical
$restoredHash = (Get-FileHash -LiteralPath $canonical -Algorithm SHA256).Hash
if (($restoredItem.Length -ne $backupItem.Length) -or ($restoredHash -cne $backupHash) -or ($restoredHash -cne $canonicalHash)) { throw 'UID0002W1 saved rollback identity mismatch; halt.' }
```
