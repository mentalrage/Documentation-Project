<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0004HV-DLPaletteCopyConstructor-empty-emitter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0004HV-DLPaletteCopyConstructor-empty-emitter-source-quality.md](0004HV-DLPaletteCopyConstructor-empty-emitter-source-quality.md)
- Source report SHA256 before cleanup: `A5405F364D5D62339A6A1204BCDAB7E34CD0C1A3333C0440C2467A32C7898C01`
- Cleanup generated: `2026-08-11T12:47:03Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `371-381`
- Original language: `powershell`
- Block SHA256: `D9A56373091FB2843DF9BD046DDA7E27E6167EA838988046D64E95D3074BE037`

```powershell
$canonical = 'E:\NTK\Resources\NexusTK\NexusTK.exe.i64'
$stamp = Get-Date -Format 'yyyyMMdd-HHmmss'
$backup = "$canonical.bak-UID0004HV-prestate-$stamp"
Copy-Item -LiteralPath $canonical -Destination $backup -ErrorAction Stop
$canonicalItem = Get-Item -LiteralPath $canonical
$backupItem = Get-Item -LiteralPath $backup
$canonicalHash = (Get-FileHash -LiteralPath $canonical -Algorithm SHA256).Hash
$backupHash = (Get-FileHash -LiteralPath $backup -Algorithm SHA256).Hash
if (($canonicalItem.Length -ne $backupItem.Length) -or ($canonicalHash -cne $backupHash)) { throw 'UID0004HV prestate backup mismatch; abort before IDA mutation.' }
```

## Removed Block R002

- Original source lines: `469-474`
- Original language: `powershell`
- Block SHA256: `C7F36F2E46CC3954DAAC5BB09C3184DAF7AB263D99704EB429DE628EA42A7CB9`

```powershell
Copy-Item -LiteralPath $backup -Destination $canonical -Force -ErrorAction Stop
$restoredItem = Get-Item -LiteralPath $canonical
$restoredHash = (Get-FileHash -LiteralPath $canonical -Algorithm SHA256).Hash
if (($restoredItem.Length -ne $backupItem.Length) -or ($restoredHash -cne $backupHash) -or ($restoredHash -cne $canonicalHash)) { throw 'UID0004HV saved rollback restore mismatch; halt.' }
```
