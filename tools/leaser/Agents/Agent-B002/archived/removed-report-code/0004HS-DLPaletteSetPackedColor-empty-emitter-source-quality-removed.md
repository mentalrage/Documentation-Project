<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0004HS-DLPaletteSetPackedColor-empty-emitter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0004HS-DLPaletteSetPackedColor-empty-emitter-source-quality.md](0004HS-DLPaletteSetPackedColor-empty-emitter-source-quality.md)
- Source report SHA256 before cleanup: `54DFB5C1CE208CF214E0F9EB972EA40FA6BA4390DC60417EFD92D07DB773B035`
- Cleanup generated: `2026-08-11T12:47:03Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `358-368`
- Original language: `powershell`
- Block SHA256: `626F180D31197BC3339C1A5AF3054D8CE1C09269BFBB40A808BDC231C56DF5FD`

```powershell
$canonical = 'E:\NTK\Resources\NexusTK\NexusTK.exe.i64'
$stamp = Get-Date -Format 'yyyyMMdd-HHmmss'
$backup = "$canonical.bak-UID0004HS-prestate-$stamp"
Copy-Item -LiteralPath $canonical -Destination $backup -ErrorAction Stop
$canonicalItem = Get-Item -LiteralPath $canonical
$backupItem = Get-Item -LiteralPath $backup
$canonicalHash = (Get-FileHash -LiteralPath $canonical -Algorithm SHA256).Hash
$backupHash = (Get-FileHash -LiteralPath $backup -Algorithm SHA256).Hash
if (($canonicalItem.Length -ne $backupItem.Length) -or ($canonicalHash -cne $backupHash)) { throw 'UID0004HS prestate backup mismatch; abort before IDA mutation.' }
```

## Removed Block R002

- Original source lines: `410-418`
- Original language: `powershell`
- Block SHA256: `8A8027A6021ABD6240CA6D0270A4183F3DB3E0C1CC3FE80C10EBB8AC6031CDC1`

```powershell
$workerPid = [int]'<gate2b-worker-pid>'
Stop-Process -Id $workerPid -Force -ErrorAction Stop
for ($i = 0; $i -lt 50 -and (Get-Process -Id $workerPid -ErrorAction SilentlyContinue); $i++) { Start-Sleep -Milliseconds 100 }
if (Get-Process -Id $workerPid -ErrorAction SilentlyContinue) { throw 'UID0004HS mutated worker did not stop; halt without save.' }
$currentItem = Get-Item -LiteralPath $canonical
$currentHash = (Get-FileHash -LiteralPath $canonical -Algorithm SHA256).Hash
if (($currentItem.Length -ne $canonicalItem.Length) -or ($currentHash -cne $canonicalHash)) { throw 'UID0004HS no-save rollback disk identity drifted; halt.' }
```

## Removed Block R003

- Original source lines: `424-433`
- Original language: `powershell`
- Block SHA256: `6EC5A4E8C312A34B762DC9DB5906A7EC63D4DF277EF2ABFC5547470CF5BDD38C`

```powershell
$persistWorkerPid = [int]'<persist-worker-pid>'
Stop-Process -Id $persistWorkerPid -Force -ErrorAction Stop
for ($i = 0; $i -lt 50 -and (Get-Process -Id $persistWorkerPid -ErrorAction SilentlyContinue); $i++) { Start-Sleep -Milliseconds 100 }
if (Get-Process -Id $persistWorkerPid -ErrorAction SilentlyContinue) { throw 'UID0004HS persistence worker did not stop; halt before disk restore.' }
Copy-Item -LiteralPath '<backup-path>' -Destination $canonical -Force -ErrorAction Stop
$restoredItem = Get-Item -LiteralPath $canonical
$restoredHash = (Get-FileHash -LiteralPath $canonical -Algorithm SHA256).Hash
if (($restoredItem.Length -ne $backupItem.Length) -or ($restoredHash -cne $backupHash) -or ($restoredHash -cne $canonicalHash)) { throw 'UID0004HS saved rollback restore identity mismatch; halt.' }
```
